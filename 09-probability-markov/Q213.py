
def JumpingSimulator(startX,startY,size=30):
    grid = [[0.0]* size for _ in range(size)]
    #* create an empty grid filled with 0
    grid[startX][startY] = 1.0 
    #* initialise the start grid space

    for _ in range(50):#* simulate 50 jumps
        newGrid = [[0.0]* size for _ in range(size)]
        for row in range(0,30):
            for col in range(0,30):
                prob = grid[row][col]
                if prob == 0:
                    continue
                neigh = []#* need to collect neighbhour nodes
        

                if row> 0: neigh.append((row-1,col))
                if row < 29: neigh.append((row+1,col))
                if col > 0: neigh.append((row,col-1))
                if col < 29: neigh.append((row,col+1))

                share = prob/len(neigh)
                #* each neighbour gets an even split of prob
                for newRow,newCol in neigh:
                    newGrid[newRow][newCol] += share
        grid = newGrid #* update the grid and repeat 50 times!
    return grid


size = 30
calcGrid = [[1.0]* size for _ in range(size)]
#* initialise a grid with all 1s ready for multiplication

for row in range(30):
    for col in range(30):
        grid = JumpingSimulator(row, col)
        #*compute probability distribution for all starts
        for r in range(30):
            for c in range(30):
                calcGrid[r][c] *= (1 - grid[r][c])   
                #*multiply all start positions together
                #* for a given end position

total = 0

for row in range(0,30):
    for col in range(0,30):
        total += calcGrid[row][col]#*sum all 900 positions

print(total)


