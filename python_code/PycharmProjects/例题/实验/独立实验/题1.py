# include <stdio.h>
# 有数字1，2，3，4，它们可以组成多少不同种的三位数？它们是多少？

# i = 0
# for a in range(1, 5):
#     num = a
#     temp1 = num
#     for b in range(1, 5):
#         num = num + b * 10
#         temp2 = num
#         for c in range(1, 5):
#             num = num + c * 100
#             print(num)
#             i = i + 1
#             num = temp2
#             if c == 4:
#                 num = temp1
#
# print("i=", i)
i = 0
for a in range(1, 5):
    for b in range(1, 5):
        for c in range(1, 5):
            if c != b and a != c and b != a:
                num = a + b * 10 + c * 100
                print(num)
                i = i + 1
print("i=", i)
