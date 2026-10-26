class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        for(;i < n; i++){
            if(nums[i] == 0) break;
        }

        int j = i+1;
        
        while(j < n){
            if(nums[j] != 0){
                swap(nums[i],nums[j]);
                ++i;
            }
            j++;
        }
    }
};