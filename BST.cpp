#include<bits/stdc++.h>
using namespace std;
//NODE CLASS
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){
        this->val=0;
        this->left=NULL;
        this->right=NULL;
    }
    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
    TreeNode(int val, TreeNode* left, TreeNode* right){
        this->val=val;
        this->left=left;
        this->right=right;
    }
};

//INSERT AN ELEMENT VAL IN THE TREE
TreeNode* insert(TreeNode* root, int val){
    if(!root){
        TreeNode* newNode=new TreeNode(val);
        return newNode;
    }
    if(val>root->val){
        root->right=insert(root->right, val);
    }
    else if(val<root->val){
        root->left=insert(root->left, val);
    }
    return root;
}

//FIND AN ELEMENT IN THE TREE
TreeNode* find(TreeNode* root, int val){
    if(!root) return NULL;
    if(root->val==val) 
        return root;
    else if(root->val>val) 
        return find(root->left, val);
    else 
        return find(root->right, val); 
    return NULL;
}

//DELETE NODE
TreeNode* deleteNode(TreeNode* root, int val){
    if(!root) return NULL;
    if(root->val>val){
        root->left=deleteNode(root->left, val);
    }
    else if(root->val<val){
        root->right=deleteNode(root->right, val);
    }
    else{
        //CASE 1: LEAF NODE
        if(!root->left && !root->right){
            delete(root);
            return NULL;
        }

        //CASE 2: SINGLE CHILD
        if(!root->left){
            TreeNode* temp=root->right;
            delete root;
            return temp;
        }
        if(!root->right){
            TreeNode* temp=root->left;
            delete root;
            return temp;
        }

        //CASE 3: TWO CHILDREN
        else{
            TreeNode* successor=root->right;
            while(successor->left){
                successor=successor->left; //FIND THE SMALLEST ELEMENT IN THE RIGHT SUBTREE OF ROOT
            }
            root->val=successor->val; //SWAP THE VALUES OF ROOT WITH THE INORDER SUCCESSOR
            root->right=deleteNode(root->right, successor->val); //DELTE THE SUCCESSOR
        }
    }
    return root;
}

//INORDER TRAVERSAL
void dfs(TreeNode* root){
    if(!root) return;
    dfs(root->left);
    cout<<root->val<<' ';
    dfs(root->right);
}

int main(){
    TreeNode* root=NULL;
    vector<int> values={4, 5, 7, 1, 3, 2};
    for(int val:values){
        root=insert(root, val);
    }
    dfs(root);
    cout<<'\n';
    TreeNode* idx=find(root, 3);
    if(idx) cout<<"FOUND "<<idx->val<<" at "<<idx<<'\n';
    else cout<<"DOES NOT EXIST"<<'\n';
    return 0;
}
