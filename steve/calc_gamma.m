function P = calc_gamma(G,N)
    if (~exist('N', 'var'))
        N = 3;
    end
    u = linspace(0,1,256);
    y = u.^(1/G);
    %P = zeros(N+1,1);
    %P(end-1) = 1;
    P = polyfit(u,y,N);

