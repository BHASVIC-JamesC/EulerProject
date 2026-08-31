import heapq

matrix_file = "matrix83.txt" 

grid = []
with open(matrix_file, "r") as f:
    for line in f:
        # strip newline, split by commas, convert to ints
        row = [int(x) for x in line.strip().split(",")]
        grid.append(row)

n = len(grid)
dist = [[10**18]*n for i in range(0,n)]
#creating a 80x80 array with large values in each cell
dist[0][0] = grid[0][0]
#initiate top left index

#create a min heap
heap = [(grid[0][0],0,0)]

# 4-neighbour directions: down, up, right, left
dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

while heap:
    cost, r, c = heapq.heappop(heap)

    #If this heap entry is stale (we found a better route later), ignore it
    if cost != dist[r][c]:
        continue

    #When we reach the target, it is gaurenteed optimal so print it
    if r == n-1 and c == n-1:
        print(cost)
        break

    for dr, dc in dirs:
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < n:
                new_cost = cost + grid[nr][nc]
                if new_cost < dist[nr][nc]:
                    dist[nr][nc] = new_cost
                    heapq.heappush(heap, (new_cost, nr, nc))

print(dist[n-1][n-1])
    