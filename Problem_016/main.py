import math

BIGNUM = 1000

answer = 0

largeNum = pow(2, BIGNUM)
print (largeNum)

for i in range(0, math.ceil(math.log10(largeNum)) + 1):
    answer += largeNum % 10
    print (answer)
    print (largeNum)
    largeNum = largeNum // 10

print ("\n", answer)
