#include"btree.cpp"				//包含二叉树的基本运算算法 
int leafnodes(TreeNode* b)
{
	if(b==NULL)								//空树 
		return 0;
	if(b->left==NULL && b->right==NULL)			//只有一个叶子结点
		return 1; 
	else										//其他情况
		return leafnodes(b->left)+leafnodes(b->right); 
}
int main()
{
	TreeNode* b;
	vector<int> a={1,3,5,null,null,4};
	b=CreateBTree(a);
	printf("b: "); DispBTree(b); printf("\n");
	printf("叶子结点个数=%d\n", leafnodes(b));
	DestroyBTree(b);
	return 0;
}
