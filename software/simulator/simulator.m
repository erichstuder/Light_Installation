close all
clear all
f=figure
hold on

x = []
y = []
z = []
c = []
for xx = 0:4
  for yy = 0:4
    for zz = 0:14
      x = [x xx];
      y = [y yy];
      z = [z zz];
      c = [c ; [rand(), rand(), rand()]];
    endfor
  endfor
endfor

xlabel('x');
ylabel('y');
zlabel('z');

tic

c = zeros(5*5*15, 3)
for n=1:100
  c(:,1) += 0.1;
  if c(1) > 1
    c(:) = 0;
  endif
  scatter3(x, y, z, 20, c);
  #pause(0.001)
  
  refresh(f)
  #drawnow()
endfor
toc

