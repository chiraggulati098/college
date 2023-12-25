%P5_3 using plot function to plot a parabola

a = 1;
x = -5:0.1:5;  
y = a * x.^2;   % x.^2 means raising every value in x to the power 2

plot(x, y)
grid on