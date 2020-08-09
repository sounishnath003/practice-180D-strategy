# Problem Link
# https://www.hackerrank.com/challenges/crush/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=arrays

n, m = map(int, input().split())
q = [0] * (n + 2)

for _ in range(m):
    a, b, k = map(int, input().split())
    q[a] += k
    q[b + 1] -= k
    
# print(q)
ans = cursum = 0
for x in q:
    cursum += x
    ans = max(cursum, ans)

print(ans)
