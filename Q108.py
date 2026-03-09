count = 0
for n in range(1,1000):
    count = 0
    for x in range(1,1000):
        for y in range (1,x+1):
            nTest = y*x/(x+y)
            if nTest == n:
                count+=1
                if (count>1000):
                    print(n)
                    break

print("done running")
    

