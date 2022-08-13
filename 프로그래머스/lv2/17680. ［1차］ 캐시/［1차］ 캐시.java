import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        
        int ret = 0;
        ArrayList cache = new ArrayList();
        
        for(int i = 0; i < cities.length; i++){
            String lo = cities[i].toLowerCase();
            
            if(cache.remove(lo)){
                ret += 1;
                cache.add(lo);
            } else {
                ret += 5;
                cache.add(lo);
                
                if(cacheSize < cache.size()){
                    cache.remove(0);
                }
            }            
        }
        return ret;
    }
    
    
    
}