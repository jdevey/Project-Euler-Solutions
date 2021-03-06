import math

#big = 28123
big = 21000

def isAbund(n):
    if (n < 12): return False
    
    sqt = int(math.sqrt(n))

    facSum = 1

    for i in range (2, sqt + 1):
        if (n % i == 0):
            facSum += i
            if (i * i != n): facSum += n // i

    #if (facSum > n): print (n)

    return True if facSum > n else False

abunList = []

for i in range (1, big + 1):
    if (isAbund(i)):
        abunList.append(i)
        #print (i)

numList = [False] * (big + 1)
size = len(abunList)

for i in range (0, size):
    for j in range (i, size):
        sum1 = abunList[i] + abunList[j]
        if (sum1 <= big):
            numList[sum1] = True

grandSum = 0 #3965432

for i in range (1, big + 1):
    if (not numList[i]): grandSum += i
    #print(i,": ",numList[i]," - ",grandSum)

print (grandSum)
