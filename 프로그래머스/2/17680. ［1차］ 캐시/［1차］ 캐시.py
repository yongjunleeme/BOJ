def solution(cacheSize, cities):
    from collections import deque
    q = deque(maxlen=cacheSize)
    ans = 0
    for city in cities:
        city = city.lower()
        
        if city in q:
            q.remove(city)
            q.append(city)
            ans += 1
        else:
            q.append(city)
            ans += 5
        
            
    return ans