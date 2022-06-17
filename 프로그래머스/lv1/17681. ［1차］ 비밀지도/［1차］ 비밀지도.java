class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        for(int i = 0; i < n; i++){
            answer[i] = i2str3(arr1[i] | arr2[i], n);
        }        
        return answer;
    }
    
    public String i2str2(int x, int n){
        String tmp = "";
        for(int i = 0; i < n; i++){
            if(x % 2 == 1) tmp += '#';
            else tmp += ' ';
            x /= 2;
        }
        String ret = "";        
        for(int i = 0; i < n; i++){
            ret += tmp.charAt(n-1-i);
        }
        return ret;
    }
    
    public String i2str3(int x, int n){
        String ret = Integer.toBinaryString(x);
        while(ret.length() < n) ret = " " + ret;
        return ret.replace('0', ' ').replace('1', '#');
    }
}