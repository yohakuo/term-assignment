s=0;n=0;
for i=2:49
   b=i*(i+1)-1;
   m=fix(sqrt(b));
   for j=2:m
      if rem(b,j)==0
         break
      end
   end
   if j==m
      n=n+1;
      s=s+b;
   end
end
n
s
