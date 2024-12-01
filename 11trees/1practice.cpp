#include <bits/stdc++.h>
using namespace std;

// implimentation of a tree 

class node {
    
    public :
       int data;
       node* left;
       node* right;
       
       node(int data){
           this->data=data;
           this->left=NULL;
           this->right=NULL;
       }
};

node* createtree(){
    int data;
    cin>>data;
    
    if(data==-1){
        return NULL;
    }
    
    node * temp = new node(data);
    
    //left 
    temp->left=createtree();
    // right
    temp->right=createtree();
    
    return temp;
}
// traversals 

void preorder(node *n1){
    if(n1==NULL){
        return;
    }
    cout<<n1->data<<" ";
    preorder(n1->left);
    preorder(n1->right);
}
void inorder(node *n1){
    if(n1==NULL){
        return;
    }
    inorder(n1->left);
    cout<<n1->data<<" ";
    inorder(n1->right);
}

void postorder(node *n1){
    if(n1==NULL){
        return;
    }
    postorder(n1->left);
    postorder(n1->right);
    cout<<n1->data<<" ";
}

void bfs_traversal(node * n1){
    queue<node*> q;
    q.push(n1);

    while (!q.empty())
    {
        node * temp= q.front();
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

void level_traversal(node *n1){
    queue<node*> q;
    q.push(n1);
    q.push(NULL);

    // here teo conditiond occcurs 
    while(!q.empty()){
        node * temp=q.front();
        q.pop();


        // 1 if the present node is null or not 
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<< temp->data<<" ";

            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
    
}
// ----------------------------height of a tree -----------------
// 1using recurssion method 
int height_tree(node *n1 ){
    if(n1==NULL){
        return 0;
    }

    int l_height=height_tree(n1->left);
    int r_height=height_tree(n1->right);

    int ans=max(l_height,r_height)+1;

    return ans;
}
// 2 usng level traversal method 
int height_tree2(node *n1){
    queue<node*> q;
    int count=0;
    q.push(n1);
    q.push(NULL);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        if(temp==NULL){
            count++;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
    return count;
}

// =================== diameter of a tree ==================================
int solve1(node* n1 , int &maxi){
    if(n1==NULL){
        return 0;
    }

    int left_len=solve1(n1->left,maxi);
    int right_len=solve1(n1->right,maxi);

    maxi=max(maxi,(left_len+right_len));

    return 1+max(left_len,right_len);
}
int diameter_tree(node *n1){
    int max_diameter=0;

    int ans=solve1(n1,max_diameter);

    return max_diameter;
}
//  ================check if the given the given tree is balanced or not=====================

bool balanced_tree(node* n1){
    if(n1==NULL){
        return true;
    }

    int left_height=height_tree(n1->left);
    int right_height=height_tree(n1->right);
    int diff=abs(left_height-right_height);
    bool ans=(diff<=1);
    if(ans==false) return false;
    bool l_tree=balanced_tree(n1->left);
    bool r_tree=balanced_tree(n1->right);

    if(ans && l_tree && r_tree){
        return true;
    }else return false;
}


int main(){
    node *n1=createtree();
    // bfs_traversal(n1);
    // cout<<endl;
    level_traversal(n1);

    // preorder(n1); cout<<endl;
    // inorder(n1); cout<<endl;
    // postorder(n1);

    // --------------------------------------------------------------
    // int height=height_tree(n1);
    // cout<<height;
    // cout<<endl;
    // int height1=height_tree2(n1);
    // cout<<height1;
    // --------------------------------------------------------------
 
// =================== diameter of a tree ==================================
    // int diameter_of_tree=diameter_tree(n1);
    // cout<<"Diameter of the tree : "<<diameter_of_tree<<endl;
// 1
// 2
// 3
// -1
// -1
// 4
// -1
// -1
// 5
// 6
// -1
// -1
// 7
// 8
// -1
// -1
// -1

//  ================check if the given the given tree is balanced or not=====================
if(balanced_tree(n1)){
    cout<<"is balanced tree"<<endl;
}else {
    cout<<"not balanced"<<endl;
}

    return 0;
}