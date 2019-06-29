primeCheck = [1 for _ in range(1001)]
primeCheck[0], primeCheck[1] = 0, 0
for p in range(1001):
    if primeCheck[p]:
        t = 2 * p
        while t <= 1000:
            primeCheck[t] = 0
            t += p

n, answer = int(input()), 0
for k in map(int, input().split()):
    answer += primeCheck[k]

print(answer)