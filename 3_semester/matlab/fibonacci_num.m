% fibonacci_num function for m16.m

function fibo = fibonacci_num(num)
    if (num <= 0)
        fibo = 0;
        return
    end
    if (num == 1)
        fibo = 0;
        return
    end
    if (num == 2)
        fibo = 1;
        return
    end
    fibo = fibonacci_num(num-1) + fibonacci_num(num-2);
    return
end