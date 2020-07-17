def prime(n):
    c = 0
    for i in range(2, n + 1):
        if n % i == 0:
            c += 1
    return c


inp1, inp2 = input().split()
n = int(inp1)
m = int(inp2)
lst = []
for i in range(n, m+1):
    if prime(i) <= 1:
        lst.append(i)

lst2 = []
for i in lst:
    for j in lst:
        newp = int(str(i) + str(j))
        if prime(newp) < 2 and newp not in lst2 :
            lst2.append(newp)

a = min(lst2)
b = max(lst2)

for i in range(len(lst2) - 2):
    c = a + b
    a,b = b,c

print(c)