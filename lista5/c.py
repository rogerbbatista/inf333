import math

while (True):
    try:
        num, exp1, exp2 = [int(i) for i in input().split()]
    except:
        break
    print ('(',num,'^',exp1,'-1)/(',num,'^',exp2,'-1)', end=" ", sep="")
    if exp1 == 0 or exp2 == 0:
        print ("is not an integer with less than 100 digits.")
        continue
    if exp1 == exp2:
        print (1)
        continue
    if num == '1':
        print ("is not an integer with less than 100 digits.")
        continue
    if exp1 < exp2 or exp1%exp2:    
        print ("is not an integer with less than 100 digits.")
        continue
    if math.log10(num) * (exp1-exp2) > 99:
        print ("is not an integer with less than 100 digits.")
        continue
    firstVal = num**exp1-1
    secondVal = num**exp2-1
    firstVal = firstVal // secondVal
    print (firstVal)