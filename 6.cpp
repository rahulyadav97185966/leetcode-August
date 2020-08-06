//find all Duplicates in Array
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        map<int,int> mp;
        if(nums.size() < 2)
            return v;
        else{
            for(int i:nums)
                mp[i]++;
            
            
            for (auto x : mp) {
                if(x.second > 1)
                    v.push_back(x.first);
            }
            return v;
            
        }
        
    }
};
