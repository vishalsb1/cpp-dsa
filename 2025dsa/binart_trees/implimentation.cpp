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
}
Node *create_tree(){
    int data;
    cin>>data;
    
    if(data==-1){
        return NULL;
    }
    node *newnode=new node(data);

    // left la create karaycha
    newnode->left=create_tree();

    // atta right cha
    newnode->right=create_tree();

    return newnode;

}
int main(){
    Node *n1=create_tree();
    cout<<n1->data;
    return 0;

}