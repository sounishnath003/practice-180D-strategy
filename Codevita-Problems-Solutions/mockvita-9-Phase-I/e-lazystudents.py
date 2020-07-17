import math

def mult_inverse(a, b, prime):
    return (a % prime * b % prime) % prime

K = int(input())
mod = 10**9+7

pascals = [ [0 for i in range(1001)] for j in range(1001) ]
pascals[0][0] = 1

for i in range(1, len(pascals)):
    pascals[i][0] = 1
    for j in range(1, i+1):
        pascals[i][j] = (pascals[i-1][j-1] + pascals[i-1][j]) % mod

for case in range(K):
    N, T, M = list(map(int, input().split()))
    if N-M < T:
        print(1)
        continue
    if M == 0:
        print(0)
        continue
    denominator = pascals[N][T]
    numerator = pascals[N-M][T]
    p = denominator - numerator
    q = denominator
    g = math.gcd(p,q)
    p //= g
    q //= g
    q_inv = pow(q, mod-2, mod)
    answer = mult_inverse(a=p, b=q_inv, prime=mod)
    print(answer)