/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution 
{
public:
	
	
	TreeLinkNode* firstNotNullChild(TreeLinkNode* root)
	{
		if (root == NULL)
			return NULL;
		if (root->left != NULL)
			return root->left;
		return root->right;	
	}
	
	TreeLinkNode* findNextNodeWithChild(vector<TreeLinkNode* > &roots, int curIndex)
	{
		if (curIndex == roots.size() - 1)
			return NULL;
		TreeLinkNode* root = roots[curIndex + 1];
		if (root->left != NULL || root->right != NULL)
			return root;
		return findNextNodeWithChild(roots, curIndex + 1);
	}
	
	vector<TreeLinkNode* > connect(vector<TreeLinkNode* > &roots)
	{
		vector<TreeLinkNode* > result;
		for (int i = 0; i < roots.size(); ++ i)
		{
			TreeLinkNode* root = roots[i];
			TreeLinkNode* next = findNextNodeWithChild(roots, i);
			if (root->right != NULL) {
				if (root->left != NULL) {
					root->left->next = root->right;
					result.push_back(root->left);
				}
				result.push_back(root->right);
				root->right->next = firstNotNullChild(next);
			} else {
				if (root->left != NULL) {
					result.push_back(root->left);
					root->left->next = firstNotNullChild(next);
				}
			}
			
		}
		return result;
	}
	// works
	 void connectMine(TreeLinkNode *root) 
	{
        if (root == NULL)
			return;
		if (root->left == NULL && root->right == NULL)
			return;
		vector<TreeLinkNode* > roots;
		roots.push_back(root);
		while (!roots.empty()) 
		{
			roots = connect(roots);
		}
	}
	
	TreeLinkNode* firstNotNullChild1(TreeLinkNode* root)
	{
		if (root == NULL)
			return NULL;
		if (root->left != NULL)
			return root->left;
		if (root->right != NULL)
			return root->right;
		return firstNotNullChild1(root->next); // not NULL
	}
	
    void connectERROR(TreeLinkNode *root) 
	{
        if (root == NULL)
			return;
		if (root->left == NULL && root->right == NULL)
			return;
		TreeLinkNode* next = root->next; //  node next's left or right may be all NULL
		while (next != NULL && next->left == NULL && next->right == NULL) {
			next = next->next;
		}
		if (root->right != NULL) {
			if (root->left != NULL) {
				root->left->next = root->right;
			}
			root->right->next = firstNotNullChild1(next);
		} else {
			if (root->left != NULL)
				root->left->next = firstNotNullChild1(next);
		}
		// spcial case: {2,1,3,0,7,9,1,2,#,1,0,#,#,8,8,#,#,#,#,7}	{2,#,1,3,#,0,7,9,1,#,2,1,0,#,7,#}	{2,#,1,3,#,0,7,9,1,#,2,1,0,8,8,#,7,#}
		// so we should connect the chilidren level by level, not by recursion
        /*connect(root->left);
		connect(root->right);*/
		
		connect(root->right);
		connect(root->left);// change the order and it works!
        
    }
	
	// http://fisherlei.blogspot.com/2012/12/leetcode-populating-next-right-pointers_29.html
	 void connect(TreeLinkNode *root) 
	 {  
      
		if(root== NULL) return;  
		TreeLinkNode* p = root->next;  // the next node that the right or left node should connect to
		while(p != NULL)  
		{  
			if (p->left != NULL)  
			{  
				p = p->left;  
				break;  
			}  
			if (p->right != NULL)  
			{  
			   p = p->right;  
			   break;  
			}  
			p = p->next;  
		}  
		if (root->right != NULL)  
		{        
			root->right->next = p;  
		}  
		if (root->left != NULL)  
		{        
			root->left->next = root->right ? root->right : p;        
		}  
		connect(root->right);  // notice: 
		connect(root->left);      
    }  
	
};