N = 50
A = [[0]*(N+1) for _ in range(N+1)]
#!Creating an array of size 51, ignoring index 0
b = [1]*(N+1)
#!Creating the right hand side matrix

for d in range(1, N+1):
    row = [0]*(N+1)
    row[d] += 1
    for (r, p) in [(-2, 1/36), (-1, 2/9), (0, 1/2), (1, 2/9), (2, 1/36)]:
        #!Adding the transition probabilities to the correct index
        newD = d + r
        if newD < 0: newD = -newD
        if newD > N: newD = 2*N - newD
        if newD == 0:
            continue
        row[newD] -= p
    A[d] = row

import numpy as np

A = np.array(A)[1:N+1,1:N+1]
b = np.array(b[1:N+1])

E = np.linalg.solve(A,b)

print(E)

