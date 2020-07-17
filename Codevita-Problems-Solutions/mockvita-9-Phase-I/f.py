import math

xl = int(input())
yl = int(input())
xw = int(input())
yw = int(input())
f = float(input())

if yl+yw == 0:
  a = xl * f


print("{0:.6f}".format(math.floor(a)))