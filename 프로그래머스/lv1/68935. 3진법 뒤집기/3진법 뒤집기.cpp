#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    string tmp;
    while(n){
        tmp += (n % 3);
        n /= 3;
    }
    int num = 1;
    int ans = 0;
    for(int i = tmp.size()-1; i >= 0; i--){
        ans += (tmp[i] * num);
        num *= 3;
    } 
    return ans;
}