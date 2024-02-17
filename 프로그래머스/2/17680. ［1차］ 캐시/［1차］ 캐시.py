def solution(cacheSize, cities):
    from collections import deque
    q = deque(maxlen=cacheSize)
    ans = 0
    for i in cities:
        i = i.lower()
        if i in q:
            q.remove(i)
            q.append(i)
            ans += 1
        else:
            q.append(i)
            ans += 5        
    return ans