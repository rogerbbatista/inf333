#https://www.hackerrank.com/challenges/sam-and-substrings/problem

number = input()
n = len(number)
total = 0
uns = 1
for i in reversed(range(n)):
	total += ((i+1) * int(number[i]) * uns) %(1000000007)
	uns = (uns*10+1)%(1000000007)

print(total%(1000000007))