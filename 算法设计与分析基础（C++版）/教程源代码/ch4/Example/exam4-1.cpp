#include"btree.cpp"				//�����������Ļ��������㷨 
int leafnodes(TreeNode* b)
{
	if(b==NULL)								//���� 
		return 0;
	if(b->left==NULL && b->right==NULL)			//ֻ��һ��Ҷ�ӽ��
		return 1; 
	else										//�������
		return leafnodes(b->left)+leafnodes(b->right); 
}
int main()
{
	TreeNode* b;
	vector<int> a={1,3,5,null,null,4};
	b=CreateBTree(a);
	printf("b: "); DispBTree(b); printf("\n");
	printf("Ҷ�ӽ�����=%d\n", leafnodes(b));
	DestroyBTree(b);
	return 0;
}
