apt = [[0 for j in range(15)] for i in range(15)]
for i in range(15):
    for j in range(1, 15):
        if i == 0:
            apt[i][j] = j
        else:
            apt[i][j] = apt[i - 1][j] + apt[i][j - 1]

for _ in range(int(input())):
    a, b = int(input()), int(input())
    print(apt[a][b], flush=False)