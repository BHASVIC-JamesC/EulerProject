def safe(mat,row,col,num):
    
    for y in range(9):
        if mat[row][y] == num:
            return False
    
    for x in range(9):
        if mat[x][col] == num:
            return False
    
    #check the mini matrix
    startRow = row - (row % 3)
    startCol = col - (col % 3)
    for x in range(3):
        for y in range(3):
            if mat[startRow + x][startCol + y] == num:
                return False
    
    return True


#backtracking using recursion
def solveSudokuRec(mat, row, col):
    # base case: Reached nth column of the last row
    if row == 8 and col == 9:
        return True

    # If last column of the row go to the next row
    if col == 9:
        row += 1
        col = 0

    # If cell is already occupied then move forward
    if mat[row][col] != 0:
        return solveSudokuRec(mat, row, col + 1)

    for num in range(1, 10):
        
        # If it is safe to place num at current position
        if safe(mat, row, col, num):
            mat[row][col] = num
            if solveSudokuRec(mat, row, col + 1):
                return True
            mat[row][col] = 0

    return False

def solveSudoku(mat):
    solveSudokuRec(mat, 0, 0)
total = 0

sudokusFile = "sudokus.txt"

mat = []
with open(sudokusFile, "r") as f:
    for line in f:
        if line.startswith("G"):
            mat = []
            continue

        row = [int(x) for x in line.strip()]
        mat.append(row)

        if len(mat) == 9:
            solveSudoku(mat)
            total += mat[0][0]*100 + mat[0][1]*10 + mat[0][2]


print(total)
