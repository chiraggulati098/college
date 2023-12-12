%Armstrong Number Function 

function armstrong = armstrong_num(a)
    armstrong = 0;
    temp = a;
    len = 0;

    while (temp~=0)
        temp = int32(temp/10);
        len = len+1;
    end

    temp = a;
    sum = 0;

    for i = 1:len
       temp2 = mod(temp,10);
       sum = sum+(temp2^len);
       temp = floor(temp/10);
    end

    if (sum == a)
       armstrong = 1;
    end
    return
end