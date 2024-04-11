import random
list1 = [1, 2, 3, 4, 5, 6, 7, 8]
for x in range(1, 4):
    r = random.choice(list1)
    print("r=", r)


for x in range(1, 4):
    random.shuffle(list1)   # 换序
    print(list1)


slice1 = random.sample(list1, 4)
print("slice1:", slice1)

