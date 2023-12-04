class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> umap;
        int temp;
        for(int i = 0; i < nums.size(); i++)
        {
            if(umap.count(nums[i]))
               return{umap[nums[i]], i};
            else
            {
                
                temp = target - nums[i];
                umap[temp] = i;
            }
        }

        return {};
    }
};