class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n),pos(n);

        int preCount = nums[0];
        pre[0] = preCount;

        for(int i = 1; i < n; i++){
            preCount *= nums[i];
            pre[i] = preCount;
        }

        int posCount = nums[n-1];
        pos[n-1] = posCount;

        for(int i = n-2; i >= 0; i--){
            posCount *= nums[i];
            pos[i] = posCount;
        }

        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(i == 0) ans.push_back(pos[i+1]);
            else if(i == n-1) ans.push_back(pre[i-1]);
            else ans.push_back(pre[i-1]*pos[i+1]);
        }

        return ans;
    }
};