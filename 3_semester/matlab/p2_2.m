%P2.2 - Check if number is prime or not

num = input('Enter a number: ');

is_prime = true;

if num <= 1
    is_prime = false;
else
    for i = 2:num/2
        if mod(num, i) == 0
            is_prime = false;
            break;
        end
    end
end

if is_prime
    disp('The number is prime.');
else
    disp('The number is not prime.');
end