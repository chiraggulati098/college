%P3_1 - Fibonacci Number

num = input('enter num: ');
fib_numbers = [];

for i = 1:num
    fibo = fibonacci_num(i);
    fib_numbers(end+1) = fibo;
end

disp(fib_numbers);