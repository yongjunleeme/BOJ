#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int idx = 0;
    for(int i = 0; i < seoul.size(); i++){
        if(seoul[i] == "Kim") idx = i;
    }
    string ans = "김서방은 ";
    ans += to_string(idx);
    string a = "에 있다";
    ans += a;
    return ans;
}