def binary_search(key, list):
    low = 0
    high = len(list) - 1
    while low <= high:
        middle = int((low + high) / 2)
        if list[middle] > key:
            high = middle - 1
        elif list[middle] < key:
            low = middle + 1
        else:
            return middle
    return -1


if __name__ == '__main__':
    list1 = [2, 6, 13, 25, 28, 37, 41, 58, 69]
    key = int(input("请输入要查找的关键字："))
    location = binary_search(key, list1)
    if location != -1:
        print("要查找的关键字%d索引为%d" % (key, location))
    else:
        print("关键字%d查找失败！" % key)
