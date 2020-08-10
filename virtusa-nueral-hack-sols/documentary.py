import re
data = "UN was established on 24-10-1945. India got freedom on 15-08-1947. 24-08-1945"


def f(data):
    dates = []
    data = data.split(" ")
    for x in data:
        m = re.search('(\d+(/|-){1}\d+(/|-){1}\d{2,4})', x)
        if m is not None:
            dates.append((int(m[1].split("-")[2])))
    dates = sorted(dates)
    cnt = t = 0
    for index in range(len(dates)):
        if t < dates[index]:
            cnt += 1
            t = dates[index]
    return (cnt)

