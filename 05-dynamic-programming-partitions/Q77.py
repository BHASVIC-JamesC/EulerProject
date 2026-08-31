def sopf(n):
    #sum of dinstinct prime factors
    if n <= 1:
        return 0
    s = 0
    d = 2
    temp = n
    while d * d <= temp:
        if temp % d == 0:
            s += d
            while temp % d == 0:
                temp //= d
        d += 1
    if temp > 1:
        s += temp
    return s

def kappa(n):#kappa function

    if n <= 1:
        return 0.0
    dp = [0.0] * (n + 1)
    dp[1] = 0.0

    for m in range(2, n + 1):
        total = sopf(m)
        for j in range(1, m):
            total += sopf(j) * dp[m - j]
        dp[m] = total / m

    return dp[n]

for i in range(1,1000):
    if kappa(i) > 5000:
        print("done:", i)
        break

