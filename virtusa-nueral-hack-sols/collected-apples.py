def collectMaxApples(input1, input2):
    ans = 0
    for i in range(input1):
        apples = []
        for j in range(i, input1):
            apples.append(min(input2[i:]))
        ans = max(ans, sum(apples))
    return ans
