import math

totalperimeter = 0

LIMIT = 333333333 # realistic upper bound

for a in range(2, LIMIT):
    b = a + 1
    inside = 3*a*a - 2*a - 1

    s = int(math.isqrt(inside))
    if s*s == inside:
        # area = (a+1)*s // 4 must be integer
        if (a+1)*s % 4 == 0:
            totalperimeter += 2*a + b

print(totalperimeter)
