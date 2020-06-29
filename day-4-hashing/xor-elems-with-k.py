# Count number of subarrays with given XOR(this  clears a lot of problems)
nums = [4, 2, 2, 6, 4]
n = len(nums)
answer = 0
for i in range(n):
    xorsum = 0
    for j in range(n):
        xorsum = xorsum ^ nums[j]
        if xorsum == 6:
            answer += 1
            
print(nums)
print(answer)