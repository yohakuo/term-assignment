for i=1:100
   if i==1
      f(i)=1;
   elseif i==2
      f(i)=0;
   elseif i==3
      f(i)=1;
   else
      f(i)=f(i-1)-2*f(i-2)+f(i-3);
   end
end
max(f)
min(f)
sum(f)
length(find(f>0))
length(find(f==0))
length(find(f<0))
