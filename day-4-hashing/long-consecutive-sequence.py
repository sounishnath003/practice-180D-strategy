# Longest Consecutive Sequence
# nums = [36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42]
nums = [1, 9, 3, 10, 4, 20, 2]

cache = set()
for x in nums:
    cache.add(x)
answer = 0
for x in nums:
    if x-1 in nums:
        el = x
        a = []
        while el in cache:
            el=el+1
            a.append(answer)
            a.append(el - x)
            answer = max(a)

print(answer + 1)