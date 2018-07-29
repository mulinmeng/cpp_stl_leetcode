#include <iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL);
};


//recursive
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root==NULL)return ret;
        inorderHelper(ret,root);
        return ret;
    }
private:
    void inorderHelper(vector<int>& ret,TreeNode* root)
    {
        if(root==NULL)return;
        inorderHelper(ret,root->left);
        ret.push_back(root->val);
        inorderHelper(ret,root->right);
    }
};

class Solution2{
public:
    vector<int>inorderTraversal(TreeNode* root){
        vector<int> ret;
        if(root==NULL)return ret;
        TreeNode *curr = root;
        stack<TreeNode*> st;
        while(!st.empty()||curr!=NULL)
        {
            while(curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            ret.push_back(curr->val);
            curr=curr->right;
        }
        return ret;
    }
};

//references: https://blog.csdn.net/u012877472/article/details/49401751