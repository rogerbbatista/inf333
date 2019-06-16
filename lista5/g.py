import math

def fat(n):
    result = 1
    while (n > 1):
        result *= n
        n -= 1
    return result

def cat(fatR, n):
    result = 1
    dn = 2*n
    while (dn > n+1):
        result *= dn
        dn -= 1
    return result//fatR

n = int(input())
while (n):
    fatR = fat(n)
    result = fatR * cat(fatR, n)
    print("%d" % result)
    n = int(input())