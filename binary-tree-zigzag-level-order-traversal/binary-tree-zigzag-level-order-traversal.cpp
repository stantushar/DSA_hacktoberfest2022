#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
class TreeNode {    
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {
        val=0;
        left=NULL;
        right=NULL;
    }
    TreeNode(int val) {
        this->val=val;
        left=NULL;
        right=NULL;
    }
    TreeNode(int val, TreeNode *left, TreeNode *right) {
        this->val=val;
        this->left=left;
        this->right=right;
    }

};

vector<vector<int>> zigzagLevelOrder(TreeNode *root,vector<vector<int>> &res) {
    if (root == NULL)
        return res;
    queue<TreeNode *> q;
    q.push(root);
    
    int count = 1;
    // BFS
    while (!q.empty()) {
        vector<int> temp;
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode *cur = q.front();
            q.pop();

            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
            temp.push_back(cur->val);
        }

        if (count % 2 == 0) {
            reverse(temp.begin(), temp.end());
        }
        count++;
        res.push_back(temp);
    }
    return res;
};

//Displaying result
void printResult(vector<vector<int>> result) {
    cout<<"[";
    for(int i=0;i<result.size();i++) {
        
        for(int j=0;j<result[i].size();j++) {
            if(j==0) {
                cout<<"[";
            }
            cout<<result[i][j];
            if(j!=result[i].size()-1) {
                cout<<",";
            }
        }
        cout<<"]";
        if(i!=result.size()-1) {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}

int main() {
    //Below is a Binary Tree.
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    //Resultant Array
    vector<vector<int>> result;
    zigzagLevelOrder(root,result);

    //Displaying result
    printResult(result);
    return 0;
}