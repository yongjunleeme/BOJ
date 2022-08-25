using namespace std;

int gcd(int w, int h){
    if (h % w == 0) return w;
    else return gcd(h % w, w);
}

long long solution(int w,int h) {
    
    // w == h --> w * h - w;
    // w != h --> w * h - (w + h - gcd(w, h))
    long long ans;
    long long ww, hh;
    ww = w, hh = h;
    
    if (ww == hh) return ww * hh - ww;
    else if (ww > hh) ans = ww * hh - (ww + hh - gcd(hh, ww));
    else ans = ww * hh - (ww + hh - gcd(ww, hh));
    return ans;
    
}