%P5_4 using plot function to plot a ellipse

a=1.5;b=1;

theta = linspace(0, 2*pi, 100); % generate 100 equally distanced points between 0 and 2 pi
x = a * cos(theta);            
y = b * sin(theta);

plot(x,y)
axis equal  % make axis equal 