% max_in_array function for m15.m

function max = max_in_array(arr)
    max = arr(1);
    for i = 2:length(arr)
        if (max<arr(i))
            max = arr(i);
        end
    end
end