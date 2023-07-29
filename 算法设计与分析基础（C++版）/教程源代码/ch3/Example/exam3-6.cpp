#include"btree.cpp"			//包含二叉树的基本运算算法 
bool same(TreeNode* t1,TreeNode* t2)
{	if(t1==NULL && t2==NULL)
		return true;
	else if(t1==NULL || t2==NULL)
		return false;
	if(t1->val!=t2->val)
		return false;
	bool left=same(t1->left,t2->left);
	bool right=same(t1->right,t2->right);
	return left && right;
}
int main()
{
	TreeNode* b1,*b2;
	vector<int> a={1,3,5,null,null,4};
	b1=CreateBTree(a);
	printf("b1: "); DispBTree(b1); printf("\n");
	b2=CreateBTree(a);
	printf("b2: "); DispBTree(b2); printf("\n");
	printf("b1=b2? %d\n",same(b1,b2));
	DestroyBTree(b1);
	DestroyBTree(b2);
	return 0;
}
 
