a = input()
dic = {chr(i): 0 for i in range(97, 123)}
for i in a:
    dic[i] += 1
    
print(*list(dic.values()))
