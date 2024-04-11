import operator

a = 20
b = 20
print("a is b ?", a is b)
print("a==b?", a == b)
print("operator.eq(a,b)?", operator.eq(a, b))

x = [1, 4, 8]
y = [1, 4, 8]
print("x is y?", x is y)  # 值相同不代表是同一个变量
print("x==y?", x == y)
print("operator.eq(x,y)?", operator.eq(x, y))

a = 10
b = 20
c = 30
d = 40
e = a + b * c / d
print("e=", e)
f = (a + b) * c / d
print("f=", f)
