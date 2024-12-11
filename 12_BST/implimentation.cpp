#include <bits/stdc++.h>
using namespace std;

class Node {

    public :
        int data;
        Node* left;
        Node*right;
    
    Node (int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* insert_into_BST(Node *root,int data){
    if(root==NULL){
        // this is the firt node 
        root=new Node(data);
        return root;
    }

    // jar data null nasla tr tyo 1st data nahi a

    if(root->data > data){
        root-> left = insert_into_BST(root->left ,data);
    }
    else{
        root->right =insert_into_BST(root->right,data);
    }

    return root;
}
void create_Bstree(Node* &root){
    cout<<"enter data";
    int data;
    cin>>data;

    while(data!=-1){
        root= insert_into_BST(root,data);
        cin>>data;
    }
}

void Level_ordered_traversal(Node *n1){
    queue<Node*> q;
    q.push(n1);
    q.push(NULL);


    while(!q.empty()){
        
        Node* temp=q.front();
        q.pop();

        if( temp==NULL){
            cout<<endl;
            if(!q.empty()){
                // jar hi condition nhi lehili tar infinite loop madi adakto apan 
                q.push(NULL);
            }
        }
        else{

            cout<<temp->data<<" ";

            if(temp->left!=NULL){
                q.push(temp->left);
            }
            
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
}
bool search_bst(Node *root ,int target){
    if(root==NULL){
        return false;
    }

    if(root->data== target){
        return true;
    }

    if(root->data > target){
       return search_bst(root->left,target);
    }
    else{
       return search_bst(root->right,target);
    }
}
int main(){
    Node *root=NULL;
    create_Bstree(root);
    // 10 20 5 11 17 2 4 8 6 25 15 

    // Level_ordered_traversal(root);

    cout<<(search_bst(root,15));
    // jar 1 ala tr samjaycha true ahai mnje ki element present a 
    // or false mnje elemnt nhi mnje 0
}