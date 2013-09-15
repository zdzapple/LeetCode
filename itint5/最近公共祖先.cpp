
//返回结点node1和node2的最近公共祖先
TreeNode *getLCA(TreeNode *node1, TreeNode *node2) 
{
	TreeNode *root = node1;
	int height1 = 0;
	int height2 = 0;
	while (root->parent != NULL) {
		root = root->parent;
		height1 ++;
	}
	root = node2;
	while (root->parent != NULL) {
		root = root->parent;
		height2 ++;
	}
	if (height1 > height2)
		return getLCA(node2, node1);
	int dh = height2 - height1;
	for (int i = 0; i < dh; ++ i)
		node2 = node2->parent;
	while (node1 != node2)
	{
		node1 = node1->parent;
		node2 = node2->parent;
	}
	return node1;
		
}