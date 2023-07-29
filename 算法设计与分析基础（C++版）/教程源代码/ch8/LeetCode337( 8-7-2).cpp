class Solution {
public:
	int rob(TreeNode* root)
    	{	if (root==NULL) return 0;
        	return order(root);
    	}
    	int order(TreeNode* root)
    	{	if (root==NULL) return 0;
        	int money1=root->val;
        	if (root->left!=NULL)
            	money1+=order(root->left->left)+order(root->left->right);
        	if (root->right!=NULL)
            	money1+=order(root->right->left)+order(root->right->right);
        	int money2=order(root->left)+order(root->right);
        	return max(money1,money2);
    	}
};	
class Solution {
 	unordered_map<TreeNode*,int> hmap;
public:
    	int rob(TreeNode* root)
    	{	if (root==NULL) return 0;
        	return order(root);
    	}
    	int order(TreeNode* root)
    	{	if (root==NULL) return 0;
        	if(hmap.find(root)!=hmap.end())			//该子问题已经求出，直接返回解
            	return hmap[root];
        	int money1=root->val;
        	if (root->left!=NULL)
            	money1+=(order(root->left->left)+order(root->left->right));
        	if (root->right!=NULL)
            	money1+=(order(root->right->left)+order(root->right->right));
        	int money2=order(root->left)+order(root->right);
        	hmap[root]=max(money1,money2);
        	return hmap[root];
    	}
};

class Solution {
public:
	int rob(TreeNode* root)
    	{	if (root==NULL) return 0;
        	vector<int> dp=order(root);
        	return max(dp[0],dp[1]);
    	}
    	vector<int> order(TreeNode* root)
    	{	if (root==NULL) return {0,0};
        	vector<int> dp(2,0);
        	vector<int> leftdp=order(root->left);
        	vector<int> rightdp=order(root->right);
        	dp[0]=max(leftdp[0],leftdp[1])+max(rightdp[0],rightdp[1]);
        	dp[1]=root->val+leftdp[0]+rightdp[0];
        	return dp;
    	}
};

