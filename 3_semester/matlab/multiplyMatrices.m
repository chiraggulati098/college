function resultMatrix = multiplyMatrices (m1,m2)
    [m,n] = size(m1);
    [~,p] = size(m2);
    if n~=size(m2,1)
        error('Matrix dimensions do not match for multiplication');
    end
    resultMatrix = zeros(m,p);
    for i = 1:m
        for j = 1:p
            resultMatrix(i,j) = sum(m1(i,:).*m2(:,j)');
        end
    end
end