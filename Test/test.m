myIncludes

% sample logic
main();

function main()
    a = Files.getDir();
    b = Files.getDir('/test/asdf.m');
    
    disp('Directory A:')
    disp(strcat('   ', a))
    disp('Directory B:')
    disp(strcat('   ', b))
    
end
