//Path Sum III


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int sum, vector<int>& nums, int &res) 
    {
        if(root)
        {
            int val = root->val;
            vector<int> cpy = nums;
            
            dfs(root->left, sum, nums, res);            
            for(int i = 0; i < nums.size(); i++)
                res += (nums[i] += val) == sum;
            
            dfs(root->right, sum, cpy, res);
            for(int i = 0; i < cpy.size(); i++)
                res += (cpy[i] += val) == sum;
            
            for(int i = 0; i < cpy.size(); i++)
                nums.push_back(cpy[i]);
            
            res += val == sum;
            nums.push_back(val);
        }
    }
    
    int pathSum(TreeNode* root, int sum) 
    {
        vector<int> nums;
        int res = 0;
        dfs(root, sum, nums, res);
        return res;
    }
};
