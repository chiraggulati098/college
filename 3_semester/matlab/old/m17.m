a1 = int8(-3200);
disp(class(a1))

a2 = int16(-3200);
disp(class(a2))

a3 = int32(-3200);
disp(class(a3))

a4 = int64(-3200);
disp(class(a4))

a5 = uint8(3200);
disp(class(a5))

a6 = uint16(3200);
disp(class(a6))

a7 = uint32(3200);
disp(class(a7))

a8 = uint64(3200);
disp(class(a8))

b1 = double(1.1234567890);
fprintf("%f %s\n",b1,class(b1))

b2 = single(1.1234567890);
fprintf("%f %s\n",b2,class(b2))

d = dictionary('a','aaa','b','bbb');
disp(d('a'))