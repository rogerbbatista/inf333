t1, t2, n = map(int, input().split())
tn = 0
for i in range(n - 2):
    tn = t2**2 + t1
    t1 = t2
    t2 = tn
    
print(tn)
