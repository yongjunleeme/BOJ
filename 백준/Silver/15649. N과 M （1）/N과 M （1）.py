from itertools import permutations

def main():
    n, m = map(int, input().split())
    nums = range(1, n + 1)

    for p in permutations(nums, m):
        print(*p)

if __name__ == '__main__':
    main()
 