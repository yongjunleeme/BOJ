from itertools import combinations

n, m = map(int, input().split())
combinations_result = list(combinations(range(1, n+1), m))

for c in combinations_result:
    print(" ".join(map(str, c)))