def SieveOfEratosthenes(n):
    primes = set
    prime = [True] * (n + 1)

    p = 2
    while (p * p <= n):
        if prime[p]:
            for i in range(p * p, n + 1, p):
                prime[i] = False
        p += 1

    for p in range(2, n + 1):
        if prime[p]:
            primes.add(p)

    return primes

def is_circular_prime(n, primes):
    str_n = str(n)
    for i in range(len(str_n)):
        rotated = int(str_n[i:] + str_n[:i])
        if rotated not in primes:
            return False
    return True

#
primes = SieveOfEratosthenes(1000000)

circular_primes = [p for p in primes if is_circular_prime(p, primes)]

print("Circular primes:", circular_primes)
print("Total count:", len(circular_primes))

