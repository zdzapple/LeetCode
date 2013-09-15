#include <cmath>
//使用getLeftChildNode(TreeNode)获得左儿子结点
//使用getRightChildNode(TreeNode)获得右儿子结点
//使用isNullNode(TreeNode)判断结点是否为空
int count_complete_binary_tree_nodes(TreeNode root) 
{
	/* if (isNullNode(root))
		return 0;
	if (isNullNode(getLeftChildNode(root)))
		return 1;
	if (isNullNode(getRightChildNode(root)))
		return 2;
	int leftSum = count_complete_binary_tree_nodes(getLeftChildNode(root));
	int rightSum = count_complete_binary_tree_nodes(getRightChildNode(root));
	return leftSum + rightSum + 1; */
	if (isNullNode(root))
		return 0;
	int level = 1;
	TreeNode right = root;
	TreeNode left = root;
	while (!isNullNode(getRightChildNode(right)))
	{
		right = getRightChildNode(right);
		level ++;
	}
	
	if (level == 1)
		if (!isNullNode(getLeftChildNode(root)))
			return 2;
		else 
			return 1;
	if (!isNullNode(getLeftChildNode(right)))
		return pow(2, level) - 1 + pow(2, level) - 1;
	// find the node whose child is missing
	bool isLeft = true;
	TreeNode t = left;
	left = root;
	right = root;
	int levelNum = pow(2, level);
	TreeNode node = root;
	int begin = 1;
	int end = pow(2, level);
	// left 和 right 都指向当前子树的根节点
	for (int j = 1; j <= level - 1; ++ j)
	{
		if (isLeft) {
			t = getLeftChildNode(left);
			levelNum -= (end - begin + 1) / 2;
		} else {
			t = getLeftChildNode(right);
			levelNum += (end - begin + 1) / 2;
		}
		node = t;
		for (int i = 0; i < level - j - 1; ++ i)
		{
			node = getRightChildNode(node);
		}
		if (isNullNode(getLeftChildNode(node))) {
			// the left half			
			left = getLeftChildNode(left);
			right = left;
			isLeft = true;
			end = (begin + end - 1) / 2;
		}
		else if (!isNullNode(getRightChildNode(node))) {
			// the right half
			right = getRightChildNode(right);
			left = right;
			isLeft = false;
			begin = begin + (end - begin + 1) / 2;
		} else {
			// find
			return pow(2, level)  - 1 + levelNum - 1;
		}
			
	}
	if (isLeft) {
		return pow(2, level) - 1 + levelNum  - 2;
	} else {
		return pow(2, level) - 1 + levelNum;
	}
	
}
/**
let depth = d;
q=root;

for(i=0; i < d; i++){
    p=q->left; p=p->right->right...; depth of p is d1.
    q = (d1==d)?(q->right):(q->left);
}
**/
