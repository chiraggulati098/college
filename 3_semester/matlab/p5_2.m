%P5_2 using plot function to plot a hyperbola

b = 1;a = 1;
x = -5:0.01:5;

y_1 = sqrt((b^2)*(1 + x.^2/a^2));   % upper half
y_2 = -sqrt((b^2)*(1 + x.^2/a^2));  % lower half

plot(x,y_1,'b',x,y_2,'b');  % 'b' is for colour blue, can also give RGB values in an array [r,g,b]
grid on