from collections import deque
q = deque(["李白", "杜甫", "王维"])
q.append("韩愈")
q.append("白居易")
print("出队列元素：", q.popleft())
print("出队列元素：", q.popleft())
print("队列剩余元素：", q)
