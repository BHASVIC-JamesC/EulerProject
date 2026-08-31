from fractions import Fraction as frac
import math

def sieveOfEratosthenes(n=500):
    primes = [True for _ in range(n+1)]
    primes[0],primes[1] = False,False

    for prime in range(2, int(math.sqrt(n)) + 1):
        if primes[prime]:
            for index in range(prime * prime, n + 1, prime):
                primes[index] = False
    return primes

primes = sieveOfEratosthenes()

code = "PPPPNNPPPNPPNPN"
primeP = frac(2,3)#!prime written as P
primeN = frac(1,3)#!prime written as N
notprimeP = frac(1,3)#!not prime written as P
notprimeN = frac(2,3)#! not prime written as N

total = frac(0)

for start in range(0,500):#!Simulate all start pos
    distribution = [frac(0) for _ in range(500)]
    distribution[start] = frac(1)
    #!Initialise the distribution with the start pos
    for index in range(0,500):
        if distribution[index] != 0:
            if primes[index+1]:
                distribution[index] *= primeP if code[0] == "P" else primeN
            else:
                distribution[index] *= notprimeP if code[0] == "P" else notprimeN
    #!Compute the prime probablity based on the primality of the current index
    for croak in code[1:]:#!Compute probability for all letters in the code
        newDistribution = [frac(0) for _ in range(500)]
        for index in range(0,500):
            if distribution[index] == 0:
                continue
            prob = distribution[index]
            neigh = []#!Extract all neighbhours
            if index == 0: neigh.append(1)
            elif index == 499: neigh.append(498)
            else: 
                neigh.append(index-1) 
                neigh.append(index+1)
            share = prob/len(neigh)
            for i in neigh:
                newDistribution[i] += share#!Update jump probability
        for index in range(0,500):
            if newDistribution[index] != 0:
                if primes[index+1]:
                    newDistribution[index] *= primeP if croak == "P" else primeN
                else:
                    newDistribution[index] *= notprimeP if croak == "P" else notprimeN
        #!Compute the prime probability again after a jump occurs
        distribution = newDistribution

    total += sum(distribution)#! add up the chance of producing the code for all start pos

total /= 500#!Divide by 500 due to 500 potential start pos
print(total)