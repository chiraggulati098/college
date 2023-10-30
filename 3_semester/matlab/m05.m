grade = input('Enter Grade: ','s');

switch(grade)
    case 'A'
        fprintf('Your Grade is %s = Excellent',grade)
    case 'B'
        fprintf('Your Grade is %s = Very Good',grade)
    case 'C'
        fprintf('Your Grade is %s = Well Done',grade)
    case 'D'
        fprintf('Your Grade is %s = Passed with Distinction',grade)
    case 'E'
        fprintf('Your Grade is %s = Passed',grade)
    case 'F'
        fprintf('Your Grade is %s = FAIL',grade)
end