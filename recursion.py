def recursion(a,b,count):
    print(a)
    if count == 10:
        return
    
    return (recursion(b,a+b,count+1))

recursion(1,1,1)