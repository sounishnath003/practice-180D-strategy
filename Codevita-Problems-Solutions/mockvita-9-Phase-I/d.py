N = int(input())

r1, r2 = map(int, input().split())
target = int(input())
l1, l2 = [], []
spend, result = 0, 0
l = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
for j in range(len(l)):
    for k in range(1, l[j]+1):
        l1.append((6-(j+1))**2+abs(k-15))
    l2.append(l1)
    l1 = []
for i in range(N+1):
    for j in l2:
        for k in j:
            if(k >= N):
                t = N-i
                spend = spend+(i*r1+t*r2)
            else:
                h = N-i
                t = k-h
                if(t <= 0):
                    spend = spend+(k*r2)
                else:
                    spend = spend+(t*r1+h*r2)
        result = result+spend
        spend = 0
    if(result >= target):
        print(i)
        break
    else:
        result = 0
else:

    print(N, end=" ")
