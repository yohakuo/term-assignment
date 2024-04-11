function flag=mat3(x)
flag=1;
for i=2:sqrt(x)
if rem(x,i)==0
      flag=0;
      break;
end
end



