%P4_1 - Armstrong Number of not using Function

a = input('enter number: ');
armstrong = armstrong_num(a);
if armstrong == 1
    fprintf("%d is an armstrong number\n",a);
else
    fprintf("%d is not an armstrong number\n",a);
end