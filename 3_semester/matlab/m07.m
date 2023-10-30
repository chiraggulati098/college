k = 1;
while k
    if randi(50,1) == 10
        fprintf('The no. equivalent to 10 is found at %d step',k);
        break
    end
    k = k+1;
end