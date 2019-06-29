dice = [0 for _ in range(7)]
maxCount, maxDice = 0, 0
for d in sorted(list(map(int, input().split()))):
    dice[d] += 1
    if maxCount <= dice[d]:
        maxCount = dice[d]
        maxDice = d

answer = 0
if maxCount == 1:
    answer = maxDice * 100
elif maxCount == 2:
    answer = 1000 + maxDice * 100
else:
    answer = 10000 + maxDice * 1000
print(answer)