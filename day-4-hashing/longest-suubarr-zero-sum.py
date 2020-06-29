nums = [15, -2, 2, -8, 1, 7, 10, 23]
n = len(nums)
prefsum = 0
answer = 0
cache = {}
cache[0] = 0
for i in range(n):
    x = nums[i]
    prefsum += x
    if prefsum == 0:
        answer = i + 1
    if prefsum in cache:
        answer = max(answer, i - cache[prefsum])
    else:
        cache[prefsum] = i

print(cache)
print(answer)
