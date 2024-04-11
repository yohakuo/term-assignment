a = 0.1
b = 0.2
print("a + b =", a + b)
# compare.
if (a + b) == 0.3:
    print("(a + b) == 0.3")
else:
    print("(a + b) != 0.3")
    # compare.
    if (a + b) == 0.30000000000000004:
        print("(a + b) == 0.30000000000000004")
    else:
        print("(a + b) != 0.30000000000000004")
print("a = %.18f" % a)
print("b = %.18f" % b)
'''
验证a+b是不是该结果
'''
