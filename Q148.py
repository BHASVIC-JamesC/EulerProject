def total_not_divisible(N, p=7):
    digits = []
    temp = N
    
    while temp:
        digits.append(temp % p)
        temp //= p
    
    digits.reverse()
    
    total = 0
    prefix_product = 1
    
    length = len(digits)
    
    for i, d in enumerate(digits):
        remaining = length - i - 1
        
        for smaller in range(d):
            total += prefix_product * (smaller + 1) * (28 ** remaining)
        
        prefix_product *= (d + 1)
    
    total += prefix_product  # include N itself
    
    return total

print(total_not_divisible(10**9))