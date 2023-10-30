%WAP to display all prime numbers from 1 to 100 using nested for loop

for i=2:100
    prime = 1;
    for j=2:i/2
        if (mod(i,j) == 0)
            prime = 0;
        end
    end
    if (prime == 1)
        fprintf('%d  ',i);
    end
end