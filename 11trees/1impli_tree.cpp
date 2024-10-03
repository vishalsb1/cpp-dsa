#include<iostream>
#include<queue>
using namespace std;
class node{

    public:
     int data;
     node *left;
     node *right;

     node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
     }
};

node *create_tree(){
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

// the three traversals 
// 1.pre-order [N:L:R]
void print_preorder_traversal(node * Node1){
    if(Node1==NULL){
        return ;
    }

    // n
    cout<<Node1->data<<"-> ";
    // left
    print_preorder_traversal(Node1->left);
    // right
    print_preorder_traversal(Node1->right);
}
// 2.in-order [L:N:R]
void print_inorder_traversal(node * Node1){
    if(Node1==NULL){
        return ;
    }

    // left
    print_inorder_traversal(Node1->left);
    // n
    cout<<Node1->data<<"-> ";
    // right
    print_inorder_traversal(Node1->right);
}

// 3.post-order[L:R:N]
void print_postorder_traversal(node * Node1){
    if(Node1==NULL){
        return ;
    }

    // left
    print_postorder_traversal(Node1->left);
    // right
    print_postorder_traversal(Node1->right);
    // n
    cout<<Node1->data<<"-> ";
}

void BFS(node *n1){
    queue<node*> q;
    q.push(n1);


    while(!q.empty()){
        node* temp=q.front();
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

void Level_ordered_traversal(node *n1){
    queue<node*> q;
    q.push(n1);
    q.push(NULL);


    while(!q.empty()){
        
        node* temp=q.front();
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
int main(){

    node *n1=create_tree();
    // cout<<n1->data;

    // print_inorder_traversal(n1);
    // print_preorder_traversal(n1);
    // print_postorder_traversal(n1);
    // cout<<endl;

    // 2. bfs breath first search(level wise)
    // BFS(n1);
    Level_ordered_traversal(n1);  // hai wala level wise print karay sathi fkt manje level 0 nanter a endl
    // level 1 nanter parat ek endl 
    // and so on 
    return 0;
}