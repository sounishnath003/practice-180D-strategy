from math import *


def test_case_sounish():
    n = int(input())
    bricks = []
    answer = 0
    for i in range(n):
        a = input().split()
        bricks.append( list(map(str, a)))

    for i in range(n) :
        for j in range(n):
            if bricks[i][j] == 'D': answer += 1

    answer = floor(sqrt(answer))
    print(answer, end='\n')


if __name__ == "__main__":
    test_case_sounish()