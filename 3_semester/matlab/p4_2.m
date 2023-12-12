%P4_2 - Swap Numbers using Function

a = input('enter a: ');
b = input('enter b: ');

fprintf("a = %d     b = %d\n",a,b);
fprintf("after swapping:\n");

[a,b] = swap_func(a,b);
fprintf("a = %d     b = %d\n",a,b);