function y=PIDtuning(x)
assignin('base','Z1',x(1)); assignin('base','P1',x(2));
assignin('base','Z2',x(3)); assignin('base','P2',x(4));
assignin('base','K',x(5));  
sim('PIDtuningmodel.mdl',0.2);
y=max(sum(yy)); 
end