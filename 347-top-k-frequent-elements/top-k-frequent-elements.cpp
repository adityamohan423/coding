class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(auto it:nums) mpp[it]++;

        vector<pair<int,int>> res;

        for(auto it:mpp){
            res.push_back({it.second,it.first});
        }

        sort(res.begin(),res.end(),[](pair<int,int> a, pair<int,int> b){
            return a.first > b.first;
        });

        vector<int>ans;

        for(int i = 0; i < k; i++){
            ans.push_back(res[i].second);
        }

        return ans;
    }
};