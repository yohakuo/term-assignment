# 求1！+...+20!
s = 0

for i in range(1, 21):
    mul = 1
    while i:
        mul = mul * i
        i -= 1
    s += mul
print(s)
