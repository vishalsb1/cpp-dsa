// #include<iostream>
#include <bits/stdc++.h>
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
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// implementing an tree from preorder and in order traversal also implementing an tree from preorder and in order traversal
int find_index(int inorder[],int size,int target){
    for(int i=0;i<size;i++){
        if(inorder[i]==target){
            return i;
        }
    }
    return -1;
}


node* create_tree_from_inorder_preorder(int preorder[],int inorder[],int inorderstart,int inorderend, int &preorderIndex,int size){
    if( preorderIndex>=size || inorderstart>inorderend ){
        return NULL;
    }

    // ek condition 

    int element=preorder[preorderIndex];
    preorderIndex++;

    node* root_node=new node(element);

    int position=find_index(inorder,size,element);


    root_node->left=create_tree_from_inorder_preorder(preorder,inorder,inorderstart,position-1,preorderIndex,size);
    root_node->right=create_tree_from_inorder_preorder(preorder,inorder,position+1,inorderend,preorderIndex,size);

    return root_node;
}



node* create_tree_from_inorder_postorder(int postorder[],int inorder[],int inorderstart,int inorderend, int &postorderIndex,int size){
    if( postorderIndex>=size || inorderstart>inorderend ){
        return NULL;
    }

    // ek condition 

    int element=postorder[postorderIndex];
    postorderIndex--;

    node* root_node=new node(element);

    int position=find_index(inorder,size,element);


    root_node->right=create_tree_from_inorder_postorder(postorder,inorder,position+1,inorderend,postorderIndex,size);
    root_node->left=create_tree_from_inorder_postorder(postorder,inorder,inorderstart,position-1,postorderIndex,size);

    return root_node;
}

void print_leftview(node *root,int level,vector<int> &leftview){
    if(root==NULL){
        return ;
    }

    if(level==leftview.size()){
        leftview.push_back(root->data);
    }

    // atta left ani right cha vishay

    print_leftview(root->left,level+1,leftview);
    print_leftview(root->right,level+1,leftview);
}
/*
void print_leftview_ii(node *n1 , vector<int> &leftview){
    queue<int> q;

    q.push(n1);
    q.push(NULL);

    vector<int> temp;
    while(!q.empty()){

        node * temp = q.front();

        q.pop();

        if(root==NULL){
            // cout<<endl;
            leftview.push_back(temp.at(0));
            delete temp;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{

            // cout root cha data;
            temp.push_back((root->data));
            // att left la 
            print_leftview_ii(root->left,leftview);
            // att right la 
            print_leftview_ii(root->right,leftview);
        }
        */

void print_rightview(node *root,int level,vector<int> &rightview){
    
    if(root==NULL){
        return ;
    }

    if(level==rightview.size()){
        rightview.push_back(root->data);
    }

//    etha apan pahile right la view karto tyananter leftla 

        print_rightview(root->right,level+1,rightview);
        print_rightview(root->left,level+1,rightview);
    }

// the implimentation of top viewof a tree 

void print_topview(node *n1 )
{   
    map<int ,int > hd_to_node;
    queue<pair<node*,int>> q;
    q.push(make_pair(n1,0));

    while (!q.empty())
    {
       pair<node*,int> temp=q.front();
       q.pop();

       node* frontnd=temp.first;
       int hd=temp.second;

       if(hd_to_node.find(hd)==hd_to_node.end()){
            hd_to_node[hd]=frontnd->data;
       }

        //    atta same left la jaycha nanter rigth

        if(frontnd->left !=NULL){
            q.push(make_pair(frontnd->left,hd-1));
        }
        if(frontnd->right !=NULL){
            q.push(make_pair(frontnd->right,hd+1));
        }

    }

    for(auto i : hd_to_node){
        cout<<i.second<<" ";
    }
    
}
int main(){

    node *n1=create_tree();
    // cout<<n1->data;    //3 4 2 -1 -1 5 -1 -1 1 7 -1 -1 9 -1 -1

    // print_inorder_traversal(n1);
    // print_preorder_traversal(n1);
    // print_postorder_traversal(n1);
    // cout<<endl;

    // 2. bfs breath first search(level wise)
    // BFS(n1);
    // Level_ordered_traversal(n1);  // hai wala level wise print karay sathi fkt manje level 0 nanter a endl
    // level 1 nanter parat ek endl 
    // and so on 
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
    // implementing an tree from preorder and in order traversal

    // int preorder[]={2,8,10,6,4,12};
    // int inorder[]={10,8,6,2,4,12};
    // int inorderstart=0;
    // int inorderend=5;
    // int preorderIndex=0;
    // int size=6;
    // node* node1=create_tree_from_inorder_preorder(preorder,inorder,inorderstart,inorderend,preorderIndex,size);
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
    // implementing an tree from postorder and in order traversal 

    // int postorder[]={10,6,8,12,4,2};
    // int inorder[]={10,8,6,2,4,12};
    // int inorderstart=0;
    // int inorderend=5;
    // int size=6;
    // int postorderIndex=size-1;

    // node* node1=create_tree_from_inorder_postorder(postorder,inorder,inorderstart,inorderend,postorderIndex,size);


    // Level_ordered_traversal(node1);

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------
    // the printing of left view 

    // method i
    // vector<int> leftview;
    // print_leftview(n1,0,leftview);

    // for(auto i : leftview){
    //     cout<<(i)<<" ";
    // }

    // method ii
    // vector<int> leftview;
    // print_leftview_ii(n1,leftview);

    // for(auto i : leftview){
    //     cout<<(i)<<" ";
    // }


// -------------------------------------------------------------------------------------------------------------------------------------
    
    // vector<int> rightview;
    // print_rightview(n1,0,rightview);

    // for(auto i : rightview){
    //     cout<<(i)<<" ";
    // }
    

// -------------------------------------------------------------------------------------------------------------------------------------------
    
    // top view  
// 1
// 2
// 3
// -1
// -1
// 4
// -1
// -1
// 9
// -1
// 10
// -1
// -1
    print_topview(n1);  



    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}