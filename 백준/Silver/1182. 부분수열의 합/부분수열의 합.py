n, s = map(int, input().split())
arr = list(map(int, input().split()))
cnt = 0

def func(idx, tot):
    global cnt
    if idx == n:
        if tot == s:
            cnt += 1
        return

    func(idx+1, tot)
    func(idx+1, tot + arr[idx])


func(0, 0)
if s == 0:
    cnt -= 1
print(cnt)
