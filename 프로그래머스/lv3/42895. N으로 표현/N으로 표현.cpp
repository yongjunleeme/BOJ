#include <bits/stdc++.h>
using namespace std;

int ans = 9;
// https://mungto.tistory.com/61

void func(int N, int number, int cur, int cnt){
    if(cnt >= 9) return;
    if(cur == number){
        ans = min(ans, cnt);
        return;
    }
    int tmp = 0;
    for(int i = 0; i < 9; i++){
        tmp = tmp * 10 + N;
        
        func(N, number, cur+tmp, cnt+1+i);
        func(N, number, cur-tmp, cnt+1+i);
        func(N, number, cur/tmp, cnt+1+i);
        func(N, number, cur*tmp, cnt+1+i);        
    }    
}

int solution(int N, int number){
    func(N, number, 0, 0);
    if(ans == 9) return -1;
    return ans;
}
