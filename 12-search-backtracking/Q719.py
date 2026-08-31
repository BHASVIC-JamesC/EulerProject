def is_S_number(k):
    n = k * k
    s = str(n)
    L = len(s)
    digits = [int(ch) for ch in s]
    target = k

    # Precompute min_remain and max_remain
    min_remain = [0] * L
    max_remain = [0] * L
    sum_digits = 0
    curr = 0
    power = 1
    for i in range(L - 1, -1, -1):
        sum_digits += digits[i]
        min_remain[i] = sum_digits
        curr = digits[i] * power + curr
        max_remain[i] = curr
        power *= 10

    # DFS with pruning
    def dfs(start, current_sum, parts_count):
        if start == L:
            return current_sum == target and parts_count >= 2
        # Prune based on min and max possible sums
        if current_sum + min_remain[start] > target:
            return False
        if current_sum + max_remain[start] < target:
            return False

        num = 0
        for i in range(start, L):
            num = num * 10 + digits[i]
            if current_sum + num > target:
                break
            if dfs(i + 1, current_sum + num, parts_count + 1):
                return True
        return False

    return dfs(0, 0, 0)

def T(N):
    limit = int(N ** 0.5)
    total = 0
    for k in range(1, limit + 1):
        if k % 9 not in (0, 1):
            continue
        if is_S_number(k):
            total += k * k
    return total

if __name__ == "__main__":
    # Verify T(10^4)
    print("T(10^4) =", T(10**4))  # Should output 41333
    print("T(10^12) =", T(10**12))