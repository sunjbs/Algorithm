n = int(input())
tree = [int(input()) for _ in range(n)]
gcd = lambda a, b: gcd(b, a % b) if a % b else b
g = tree[1] - tree[0]
for i in range(2, n):
    g = gcd(g, tree[i] - tree[i - 1])
answer = (tree[n - 1] - tree[0]) // g + 1 - n
print(answer)