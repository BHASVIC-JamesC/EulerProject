target = 100 #target sum for DP

ways = [0] * (target + 1)#initilaise ways array all 0

ways[0] = 1#set the first index to be 1

for i in range(1, target):
    for j in range(i, target + 1):
        #for each index, loop through all indexes 
        #greater than the index and update ways
        ways[j] += ways[j - i]

print(ways[target])

#{shadow.jr} production!
