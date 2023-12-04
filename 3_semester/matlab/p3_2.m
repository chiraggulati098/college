%P3_2 - Factorial Number

x = input('Enter number: ');
factorial = 1;
for i = 1:x
    factorial = factorial*i;
end
disp(factorial);