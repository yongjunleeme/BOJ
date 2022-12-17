def solution(ingredient):
    tmp = []
    ans = 0
    
    for i in ingredient:
        tmp.append(i)
        
        if tmp[-4:] == [1,2,3,1]:
            ans += 1
            tmp.pop()
            tmp.pop()
            tmp.pop()
            tmp.pop()
    
    return ans