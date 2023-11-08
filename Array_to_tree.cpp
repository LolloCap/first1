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
/*Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.*/
/*L'input era un array.*/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return NULL;
        }
        if(nums.size() == 1){
            return new TreeNode(nums[0]);
        }
        int mid = nums.size()/2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> leftsub(nums.begin(),nums.begin()+mid);
        vector<int> rightsub(nums.begin()+mid+1,nums.end());
        root->left = sortedArrayToBST(leftsub);
        root->right = sortedArrayToBST(rightsub);
        return root;
    }
};