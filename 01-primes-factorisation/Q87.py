import math

def sieve(n):
    primes = [True]*(n+1)
    primes[0] = primes[1] = False

    for i in range(2,int(math.sqrt(n))+1):
        if primes[i]:
            for j in range(i*i,n+1,i):
                primes[j] = False

    return [i for i in range(n+1) if primes[i] == True]

cap = 50000000

p2 = [p**2 for p in sieve(7071)]
p3 = [p**3 for p in sieve(368)]
p4 = [p**4 for p in sieve(85)]

values = set()

for a in p2:
    for b in p3:
        if a+b >= cap:
            break
        for c in p4:
            val = a+b+c
            if val < cap:
                values.add(val)
            else:
                break

print(len(values))