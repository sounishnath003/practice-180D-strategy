import math

cache = {}
cars = int(input())
answer = 0

for i in range(cars):
    x,y,v = list(map(int, input().split()))
    # tmp = math.sqrt( (x/v)**2 + (y/v)**2 )
    tmp = math.sqrt( (x**2 + y**2) )/v
    if cache.get(tmp) == None:
        cache[tmp] = 1
    else:
        cache[tmp] += 1


for k in cache:
    if cache[k]!=1:
        answer += (cache[k] * (cache[k] - 1))/2


print(int(answer)) ;