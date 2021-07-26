class Solution {
public:
    TreeNode* convert(vector<int>& nums, int l, int r) {
        if(l > r)
            return NULL;
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left  = convert(nums, l, mid-1);
        root->right = convert(nums, mid+1, r);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums, 0, nums.size()-1);
    }
};
