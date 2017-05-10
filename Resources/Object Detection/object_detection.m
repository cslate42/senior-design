threshold = single(0.99);
level = 2;

%%
% Create System object(TM) to read a video file.
hVideoSrc = vision.VideoFileReader('asdf.mp4', ...
                                   'VideoOutputDataType', 'single',...
                                   'ImageColorSpace', 'Intensity');

%%
% Create three gaussian pyramid System objects for decomposing the target
% template and decomposing the Image under Test(IUT). The decomposition is
% done so that the cross correlation can be computed over a small region
% instead of the entire original size of the image.
hGaussPymd1 = vision.Pyramid('PyramidLevel',level);
hGaussPymd2 = vision.Pyramid('PyramidLevel',level);
hGaussPymd3 = vision.Pyramid('PyramidLevel',level);

%% 
% Create two 2-D FFT System objects one for the image under test and the
% other for the target. 
hFFT2D1 = vision.FFT;
hFFT2D2 = vision.FFT;

%% 
% Create a System object to perform 2-D inverse FFT after performing
% correlation (equivalent to multiplication) in the frequency domain. 
hIFFFT2D = vision.IFFT;

%% 
% Create 2-D convolution System object to average the image energy in tiles
% of the same dimension of the target.
hConv2D = vision.Convolver('OutputSize','Valid');

%%
% Here you implement the following sequence of operations.

% Specify the target image and number of similar targets to be tracked. By
% default, the example uses a predefined target and finds up to 2 similar
% patterns. Set the variable useDefaultTarget to false to specify a new
% target and the number of similar targets to match.
%%%%%%%%%%%%%%TODO CHANGE????????%%%%%%%%%%%%%%%%%%%%%%%
useDefaultTarget = false;
[Img, numberOfTargets, target_image] = ...
  video_gettemplate(useDefaultTarget);

% Downsample the target image by a predefined factor using the
% gaussian pyramid System object. You do this to reduce the amount of
% computation for cross correlation.
target_image = single(target_image);
target_dim_nopyramid = size(target_image);
target_image_gp = step(hGaussPymd1, target_image);
target_energy = sqrt(sum(target_image_gp(:).^2));

% Rotate the target image by 180 degrees, and perform zero padding so that
% the dimensions of both the target and the input image are the same.
target_image_rot = imrotate(target_image_gp, 180);
[rt, ct] = size(target_image_rot);
Img = single(Img);
Img = step(hGaussPymd2, Img);
[ri, ci]= size(Img);
r_mod = 2^nextpow2(rt + ri);
c_mod = 2^nextpow2(ct + ci);
target_image_p = [target_image_rot zeros(rt, c_mod-ct)];
target_image_p = [target_image_p; zeros(r_mod-rt, c_mod)];

% Compute the 2-D FFT of the target image
target_fft = step(hFFT2D1, target_image_p);

% Initialize constant variables used in the processing loop.
target_size = repmat(target_dim_nopyramid, [numberOfTargets, 1]);
gain = 2^(level);
Im_p = zeros(r_mod, c_mod, 'single'); % Used for zero padding
C_ones = ones(rt, ct, 'single');      % Used to calculate mean using conv

%% 
% Create a System object to calculate the local maximum value for the
% normalized cross correlation.
hFindMax = vision.LocalMaximaFinder( ...
            'Threshold', single(-1), ...
            'MaximumNumLocalMaxima', numberOfTargets, ...
            'NeighborhoodSize', floor(size(target_image_gp)/2)*2 - 1);

%%
% Create a System object to display the tracking of the pattern.
sz = get(0,'ScreenSize');
pos = [20 sz(4)-400 400 300];
hROIPattern = vision.VideoPlayer('Name', 'Overlay the ROI on the target', ...
    'Position', pos);

%%
% Initialize figure window for plotting the normalized cross correlation
% value
hPlot = videopatternplots('setup',numberOfTargets, threshold);

%% Video Processing Loop
% Create a processing loop to perform pattern matching on the input video.
% This loop uses the System objects you instantiated above. The loop is
% stopped when you reach the end of the input file, which is detected by
% the |VideoFileReader| System object.
while ~isDone(hVideoSrc)
    for i = 0:1000 
        Im = step(hVideoSrc);
        Im_gp = step(hGaussPymd3, Im);

        % Frequency domain convolution.
        Im_p(1:ri, 1:ci) = Im_gp;    % Zero-pad
        img_fft = step(hFFT2D2, Im_p);
        corr_freq = img_fft .* target_fft;
        corrOutput_f = step(hIFFFT2D, corr_freq);
        corrOutput_f = corrOutput_f(rt:ri, ct:ci);

        % Calculate image energies and block run tiles that are size of
        % target template.
        IUT_energy = (Im_gp).^2;
        IUT = step(hConv2D, IUT_energy, C_ones);
        IUT = sqrt(IUT);

        % Calculate normalized cross correlation.
        norm_Corr_f = (corrOutput_f) ./ (IUT * target_energy);
        xyLocation = step(hFindMax, norm_Corr_f);

        % Calculate linear indices.
        linear_index = sub2ind([ri-rt, ci-ct]+1, xyLocation(:,2),...
            xyLocation(:,1));

        norm_Corr_f_linear = norm_Corr_f(:);
        norm_Corr_value = norm_Corr_f_linear(linear_index);
        detect = (norm_Corr_value > threshold);
        target_roi = zeros(length(detect), 4);
        ul_corner = (gain.*(xyLocation(detect, :)-1))+1;
        target_roi(detect, :) = [ul_corner, fliplr(target_size(detect, :))];

        % Draw bounding box.   
        Imf = insertShape(Im, 'Rectangle', target_roi, 'Color', 'green');
        % Plot normalized cross correlation.
        videopatternplots('update',hPlot,norm_Corr_value);
        step(hROIPattern, Imf);
    end
end

release(hVideoSrc);

displayEndOfDemoMessage(mfilename)
