arr = [i for i in range(21)]
for _ in range(10):
    start, end = map(int, input().split())
    arr[start:end + 1] = arr[end:start - 1:-1]
for i in range(1, 21):
    print(arr[i], end=' ')