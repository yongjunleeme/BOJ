from collections import defaultdict

a = int(input())
b = int(input())
c = int(input()) 
n = a * b * c

dic = defaultdict(int)
for _ in range(len(str(n))):
    n, div = divmod(n, 10)
    dic[div] += 1

for i in range(10):
    print(dic[i])
