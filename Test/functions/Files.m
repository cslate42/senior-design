classdef Files
    %{
        Example sources
        https://www.mathworks.com/help/matlab/matlab_oop/create-a-simple-class.html
        https://www.mathworks.com/help/matlab/matlab_oop/specifying-methods-and-functions.html
    %}
    
    properties
        
    end
    
    methods
        
    end
    
    methods (Static)
        %{
        @param String|null path
            Optarginional - path to get file's directory from. Leave deafult
            to use callers
        %}
        function dirPath = getDir(path)
            %{
                % Get file's dir name
                % EXAMPLE ONLY WORKS WITH ITS OWN FILE
                path = mfilename('fullpath');
                positions = strfind(path, '/');
                lastKey = length( positions );
                lastSlash = int32( positions( lastKey ) );
                fileDir = path( 1 : lastSlash )
            %}
            dirPath = false;
            if nargin == 0 % # of arguments == 0 
                stack = dbstack('-completenames');
                % if ~ isempty(stack) 
                if length(stack) > 1
                    path = stack(2).file;
                end 
            end
            
            if ischar(path)
                positions = strfind(path, "/");
                lastKey = length( positions );
                lastSlash = int32( positions( lastKey ) );
                dirPath = path( 1 : lastSlash );
            end
        end
    end
    
end

