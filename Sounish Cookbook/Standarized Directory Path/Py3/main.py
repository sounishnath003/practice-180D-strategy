def solve(path):
    stack = list()
    dirs = path.split("/")

    for dir_name in dirs:
        if dir_name == ".":
            continue
        elif dir_name == "..":
            stack.pop()
        else:
            stack.append(dir_name)

    spath = "/".join(stack)
    return spath

def test():
    print(solve("/usr/bin/../bin/./scripts/.. /"))
    print(solve("/usr/bin/../bin/./scripts/../foobar.txt"))
    print(solve("/usr/bin/../../bin/./scripts/foobar.txt"))    

if __name__ == "__main__":
    test()
