import sys
import math 

def read_input():
    input = sys.stdin.readline
    N, C = map(int, input().split())
    positions = list(map(int, input().split()))
    return N, C, positions


def makeKPairs(D, k, N, positions,C):
    for start in range(N):
        end = start + N
        mid = start + N // 2

        count = 0
        i = start
        j = mid

        while i < mid and j < end:
            if D <= positions[j] - positions[i] <= C- D:
                count += 1
                i += 1
                j += 1
            else:
                i += 1

            if count >= k:
                return True

    return False

if __name__ == "__main__":
    N, C, positions = read_input()

    #duplicate positions for circle
    positions = positions + [x + C for x in positions]
    answer = []
    for k in range(1,math.floor(N/2)+ 1):
        low = 0
        high = C // 2
        answerk = 0
        while low <= high:
            mid = (low + high) // 2

            if makeKPairs(mid, k, N, positions,C):
                answerk = mid
                low = mid + 1
            else:
                high = mid - 1

        answer.append(answerk)
    print(*answer)