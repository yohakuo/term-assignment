%(1)
A=rand(1,30000);
b=mean(A)
std(A,0,2)

%(2)
max(A)
min(A)

%(3)
n=0;
for i=1:30000
if A(i)>0.5
n=n+1;
end
end
p=n/30000
