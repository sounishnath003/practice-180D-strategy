# Problem Link
# https://www.hackerrank.com/challenges/minimum-swaps-2/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=arrays

n = int(input())
a = list(map(int, input().split()))
answer = 0
used = [False] * n

for i in range(n):
    if not used[i]:
        used[i] = True
        j = a[i] - 1
        while j != i:
            used[j] = True
            answer += 1
            j = a[j] - 1

print(answer)
