%随机产生一个3位整数，将它的十位数变为0。
a=round(rand(1)*899+100)
a=str2num(num2str(a)')';
a(1,2)=0;
a=a(1,1)*100+a(1,2)*10+a(1,3)