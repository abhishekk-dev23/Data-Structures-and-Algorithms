class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int cnt = 0;
        if(n<9){
            cnt+= n;
        }
        else if(n<17){
            cnt+=n;
            cnt+=(n-8);
        }else if(n<25){
            cnt+=n;
            cnt+=(n-8);
            cnt+=(n-16);
        }else{
            cnt+=n;
            cnt+=(n-8);
            cnt+=(n-16);
            cnt+=(n-24);
        }
        return cnt;
    }
};