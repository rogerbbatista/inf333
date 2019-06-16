import math

def toBase(n, b, i = 0):
    if (n):
        return (n%10 * b**i) + toBase(n//10, b, i+1)
    else:
        return 0

x = input()
while (x != "0"):
    aux = '0'
    for i in x:
        if i > aux:
            aux = i
    i = int(aux) +1
    while (i < 100):
        a = toBase(int(x), i)
        a = math.sqrt(a)
        if int(a) == a:
            print (i)
            break
        i += 1
    x = input()