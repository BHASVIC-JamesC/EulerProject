points = [(x, y) for x in range(51) for y in range(51) if (x, y) != (0, 0)]

total = 0
for i in range(len(points)):
    for j in range(i + 1, len(points)):
        x1, y1 = points[i]
        x2, y2 = points[j]

        
        OA = x1**2 + y1**2
        OB = x2**2 + y2**2
        AB = (x1 - x2)**2 + (y1 - y2)**2

        #third face is hyp
        if OA + OB == AB:
            total +=1
        #first face is hyp
        if AB + OB == OA:
            total +=1
        #second face is hyp
        if AB + OA == OB:
            total +=1
print(total)