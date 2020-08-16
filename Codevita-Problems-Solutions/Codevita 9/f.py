def codeFindM():
    while(len(data) > 0):
        i = 0
        f = False
        while(i < len(data)):
            t = codeFind(data[i], i)
            if (t == True):
                f = True
                i = i - 1
            i = i + 1
        if (f == False):
            break


def codeFind(val, i):
    val = strNumber(val[0], val[1])
    if (val != False):
        del data[i]
        i = 0
        while(i < len(val[0])):
            codes[val[0][i][0]] = val[1][i][0]
            i = i + 1
        return True
    else:
        return False


import operator
def strNumber(val1, val2):
    t = {}
    v = {}
    for x in val1:
        if x in t.keys():
            t[x] = t[x] + 1
        else:
            t[x] = 1
    for x in val2:
        if x in v.keys():
            v[x] = v[x] + 1
        else:
            v[x] = 1
    t = sorted(t.items(), key=operator.itemgetter(1))
    v = sorted(v.items(), key=operator.itemgetter(1))

    i = 0
    while (i < len(t)):
        f = False
        if (t[i][0] in codes):
            j = 0
            while (j < len(v)):
                print(t[i][0])
                if (v[j][0] == codes[t[i][0]]):
                    del v[j]
                    break
                j = j + 1
            del t[i]
            i = i - 1
        elif (i + 1 < len(t) and t[i][1] == t[i + 1][1] and t[i + 1][0] not in codes):
            return False
        i = i + 1

    return [t, v]


def test_case():
    text = "load"
    n = 3
    data = ["app lol", "old tip", "odd itt"]
    data = [x.split() for x in data]
    codes = {}

    codeFindM()
    print(codes, data)
    cipher = ""
    for x in text:
        cipher = cipher + codes[x]
    print(cipher)



if __name__ == "__main__":
    test_case()