maxi = -1
for i in range(10000):
    concan = ""
    concan += str(i)
    start = 2
    while(len(concan) < 9):
        concan += str(i*start)
        start +=1
    if(len(concan) != 9):
        continue

    unique = {"0"}
    for i in concan:
        unique.add(i)

    if(len(unique) == 10):
        if(int(concan) > maxi):
            maxi = int(concan)
print(maxi)
