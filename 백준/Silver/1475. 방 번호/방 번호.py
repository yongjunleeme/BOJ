from collections import defaultdict

a = input()
dic = defaultdict(int)

for i in a:
    dic[i] += 1

dic['6'] = dic['9'] = (dic['6'] + dic['9'] + 1) // 2
print(max(dic.values()))