class Solution {
    String func(int x, int n){
        String ret = "";        
        for(int i = n-1; i >= 0; i--){
            if((x & (1 << i)) != 0) ret += "#";
            else ret += " ";
        }
        return ret;
    }
    
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        
        for(int i = 0; i < n; i++){
            answer[i] = func(arr1[i] | arr2[i], n);            
        }  
        
        return answer;
    }    
    
}