#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
     int data;
     Node* right;
     Node* left;

     Node(int data){
        this->data=data;
        this->right=NULL;
        this->left=NULL;
     }
};
Node *create_tree(){
    int data;
    cin>>data;
    
    if(data==-1){
        return NULL;
    }

    Node *newnode=new Node(data);

    // left la create karaycha
    newnode->left=create_tree();

    // atta right cha
    newnode->right=create_tree();

    return newnode;

}
void Level_ordered_traversal(Node *root){
    queue<Node*> q;
    q.push(root);


    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        cout<<temp->data<<" ";

        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
}
void iterative_preorder(Node* root){
    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* temp=st.top();
        st.pop();

        cout<<temp->data;
        if(temp->right!=NULL){
            st.push(temp->right);
        }
        if(temp->left!=NULL){
            st.push(temp->left);
        }
    }
}
int main(){
    Node *n1=create_tree();
    cout<<n1->data;
    // Level_ordered_traversal(n1);
    iterative_preorder(n1);
    return 0;

}