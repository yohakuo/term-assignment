import random
list1 = []
for x in range(1, 6):
    list1.append(random.randint(1, 100))
print(list1)

for x in range(1, 11):
    list1.append(random.randrange(1, 100, 2))
print(list1)


