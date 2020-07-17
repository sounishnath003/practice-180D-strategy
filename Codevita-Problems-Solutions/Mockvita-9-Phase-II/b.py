# DIGITS PAIR - BITSCORE

N = int(input())
nums = list(map(int, input().split()))

def largest(num):
    numstr =  str(num)
    i = 9
    while i >= 0:
        if str(i) in numstr:
            return i
        i -= 1

def smallest(num):
    numstr = str(num)
    i = 0
    while i <= 9:
        if str(i) in numstr:
            return i
        i += 1


bitscore = [""] * N

for i in range(len(bitscore)):
    currScore = str(11 * largest(nums[i]) + 7 * (smallest(nums[i])))
    if len(currScore) > 2:
        currScore = currScore[-2:]
    bitscore[i] = currScore


odd_freqs = [0] * 10 
even_freqs = [0] * 10


def pairs_form(n):
    if n == 2:
        return 1
    if n >= 3:
        return 2
    return 0

for i in range(len(bitscore)):
    indx = int(bitscore[i][0])
    if (i + 1) % 2 == 0 :
        even_freqs[indx] += 1
    else:
        odd_freqs[indx] += 1

count_pairs = [0] * 10

for i in range(10):
    if even_freqs[i] <= 1 and odd_freqs[i] <= 1 :
        pass
    count_pairs[i] += pairs_form(even_freqs[i]) + pairs_form(odd_freqs[i])
    count_pairs[i] = min(2, count_pairs[i])

print(sum(count_pairs), end="")