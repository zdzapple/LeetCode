/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
	bool isSymmetric(TreeNode *left, TreeNode *right)
	{
		if (left == NULL && right == NULL)
			return true;
		if (left == NULL && right != NULL)
			return false;
		if (left != NULL && right == NULL)
			return false;		
		if (left->val != right->val)
			return false;

		return (isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left));
		
	}
	
    bool isSymmetricR(TreeNode *root)  // recursively  version
	{
        if (root == NULL)
			return true;
		return isSymmetric(root->left, root->right);
    }
	
	TreeNode *nullNode;
	
	bool isSymmetric(vector<pair<TreeNode *, bool> > nodesList)
	{
		if (nodesList.size() % 2 != 0)
			return false;
		int size = nodesList.size();
		for (int i = 0; i < size / 2; ++ i)
		{
			/*if (nodesList[i].first == nullNode && nodesList[size - 1 - i].first == nullNode)
				continue;
			if (nodesList[i].first == nullNode && nodesList[size - 1 - i].first != nullNode)
				return false;
			if (nodesList[i].first != nullNode && nodesList[size - 1 - i].first == nullNode)
				return false;*/
			if (!(nodesList[i].first->val == nodesList[size - 1 - i].first->val && 
					nodesList[i].second != nodesList[size-1-i].second))
				return false;
		}
		return true;
	}
	
	bool isSymmetric(TreeNode *root)  // iteratively  version
	{
		if (root == NULL)
			return true;
		int currentLevel = 1;
		int previousLevel = 0;
		nullNode = new TreeNode(INT_MIN);
		vector<pair<TreeNode *, bool> > nodesList; // true: leftChild; false: rightChild
		nodesList.push_back(make_pair(root, false));
		previousLevel ++;
		int index;
		bool isRoot = true;
		while (currentLevel > 0)
		{
			if (!isRoot && !isSymmetric(nodesList))
				return false;
			currentLevel = 0;
			index = 0;
			while (previousLevel > 0)
			{
				TreeNode *current = nodesList[index ++].first;
				previousLevel --;
				if (current->val == INT_MIN)
					continue;
				if (current->left != NULL) {
					nodesList.push_back(make_pair(current->left, true));
				} else {
					nodesList.push_back(make_pair(nullNode, true));
				}
				if (current->right != NULL) {
					nodesList.push_back(make_pair(current->right, false));
				} else {
					nodesList.push_back(make_pair(nullNode, false));
				}
				currentLevel += 2;
			}
			nodesList.erase(nodesList.begin(), nodesList.begin() + index);
			previousLevel = currentLevel;
			isRoot = false;
		}
		return true;
    }
};