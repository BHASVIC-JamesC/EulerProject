from math import isqrt
from collections import defaultdict  

bestSum = None
best_xyz = None
bestParams = None

b = 0
while b < 1000:
    b += 1
    bSquared = b**2

    # condition 1: b^2 + f^2 = d^2
    fSquaredList = []
    for f in range(1, 1000):
        dSquared = bSquared + f**2
        d = isqrt(dSquared)
        if d*d == dSquared:
            fSquaredList.append((f, d))

    # condition 2: b^2 + e^2 = c^2
    eSquaredList = []
    for e in range(1, 1000):
        cSquared = bSquared + e**2
        c = isqrt(cSquared)
        if c*c == cSquared:
            eSquaredList.append((e, c))

    # condition 3: c^2 + f^2 = a^2  (since c^2 = b^2 + e^2)
    for (e, c) in eSquaredList:
        c2 = c*c
        for (f, d) in fSquaredList:
            aSquared = c2 + f**2
            a = isqrt(aSquared)
            if a*a != aSquared:
                continue

 

            # parity check so division by 2 is integral
            if ((aSquared + bSquared) & 1) or (((e*e) + (f*f)) & 1) or ((c2 - (d*d)) & 1):
                continue

            x = (aSquared + bSquared) // 2
            y = (e*e + f*f) // 2
            z = (c2 - d*d) // 2

            if not (x > y > z > 0):
                continue

            s = x + y + z
            if bestSum is None or s < bestSum:
                bestSum = s
                best_xyz = (x, y, z)
                bestParams = (a, b, c, d, e, f)

print("best sum:", bestSum)
print("x,y,z:", best_xyz)
print("a,b,c,d,e,f:", bestParams)
