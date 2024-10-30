class Solution {
public:
    int minimumMountainRemovals(vector<int>& v) {
        int n = v.size(),i,x;
        vector<int> l(n,0),r(n,0),s;
        s.push_back(v[0]);
        for(i = 1; i < n; i++){//longest incresing subsequence from left
            x = lower_bound(s.begin(),s.end(),v[i])-s.begin();
            if(x==s.size()){
                s.push_back(v[i]);
            }else{
                s[x] = v[i];
            }
            l[i] = i+1-s.size();
        }
        s.clear();
        s.push_back(v[n-1]);
        for(i = n-2; i >= 0; i--){//longest incresing subsequence from right
            x = lower_bound(s.begin(),s.end(),v[i])-s.begin();
            if(x==s.size()){
                s.push_back(v[i]);
            }else{
                s[x] = v[i];
            }
            r[i] = n-1-i+1-s.size();
        }
        int ans = n;
        for(i = 0; i < n; i++){
            if(i+1-l[i]>=2 && n-i-r[i]>=2)//>=2 bcz from left and right at least 2 element must be there a<b>c 
//i+1-l[i] and n-i-r[i] tells us no of element which we want delete from left and right.
                ans = min(ans,l[i]+r[i]);
        }
        return ans;
    }
};
