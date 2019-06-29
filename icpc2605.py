n, rank = int(input()), list(map(int, input().split()))
arr = []
for i, r in enumerate(rank):
    arr.insert(r, i + 1)
arr.reverse()
for k in arr:
    print(k, end = ' ')
print()
