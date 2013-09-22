/*树结点的定义(请不要在代码中定义该结构)
struct TreeNode {
  TreeNode *left, *right;
  bool isLeftThread, isRightThread;
}*/

void convertToThreadedTreeRecursion(TreeNode *p, TreeNode *&pre, TreeNode *&last) 
{
	if (!p) return;
	if (!p->isLeftThread) convertToThreadedTree(p->left, pre, p);
	if (p->left == NULL) {
		p->isLeftThread = true;
		p->left = pre;
	}
	if (p->right == NULL) {
		p->isRightThread = true;
		p->right = last;
	}
	if (!p->isRightThread) convertToThreadedTree(p->right, p, last);
	
}

void convertToThreadedTree(TreeNode *root) 
{
	/*TreeNode *pre = NULL;
	TreeNode *last = NULL;
	convertToThreadedTreeRecursion(root, pre, last);*、
	
	
}