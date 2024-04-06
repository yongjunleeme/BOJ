a, b, c = map(int, input().split())


def func(a, b):
    if b == 0:
        return 1
    elif b % 2:
        return (func(a, b // 2) ** 2 * a) % c
    else:
        return (func(a, b // 2) ** 2) % c


print(func(a, b) % c)
