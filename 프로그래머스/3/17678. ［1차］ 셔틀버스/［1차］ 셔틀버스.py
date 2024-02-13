def solution(n, t, m, timetable):
    timetable = [
        int(time[:2]) * 60 + int(time[3:])
        for time in timetable
    ]
    timetable.sort()
    cur = 540
    ans = 0
    for _ in range(n):
        for _ in range(m):
            if timetable and timetable[0] <= cur:
                ans = timetable.pop(0) - 1
            else:
                ans = cur
        cur += t
    
    h, m = divmod(ans, 60)
    return f"{str(h).zfill(2)}:{str(m).zfill(2)}"
                
            