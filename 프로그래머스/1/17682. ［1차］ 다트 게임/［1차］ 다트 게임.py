def solution(d):    
    ans = [0]
    for i in d:
        if i == 'S':
            ans[-1] **= 1
            ans.append(0)
        elif i == 'D':
            ans[-1] **= 2
            ans.append(0)
        elif i == 'T':
            ans[-1] **= 3
            ans.append(0)
        elif i == '*':            
            ans[-2] *= 2
            if len(ans) > 2:
                ans[-3] *= 2
        elif i == '#':
            ans[-2] *= -1                             
        else:
            ans[-1] = ans[-1] * 10 + int(i)
    
    return sum(ans)
            
        
    print(ans)
    return sum(ans)
            
        
    