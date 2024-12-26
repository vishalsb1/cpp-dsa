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

int largest_node(Node *n){
    if(!n){
        return 0; 
    }
    if(n->right == NULL){
        return n->data;
    }
    if(n->right!=NULL){
        return largest_node(n->right);
    }
    return 0;
}
// iterative method
int largest_iterative(Node* root){
    if(!root) return 0;
    if(root->right==NULL) return root->data;
    while(root!=NULL){
        Node * ans=root->right;
        if(ans->right==NULL){
            return ans->data;
        }
        root=root->right;
    }
    return 0;
}
int smallest_iteration(Node* root){
    if(!root) return 0;
    if(root->left==NULL) return root->data;
    while(root!=NULL){
        Node * ans=root->left;
        if(ans->left==NULL){
            return ans->data;
        }
        root=root->left;
    }
    return 0;
}
int smallest_node(Node *n){

    if(!n){
        return 0; 
    }
    if(n->left == NULL){
        return n->data;
    }
    if(n->left!=NULL){
        return smallest_node(n->left);
    }
    return 2;
}

Node* deleteNodeInBST(Node* root, int target) {
	
	//base cae
	if(root == NULL ) {
		return NULL;
	}
//cout << "Request recieved for " >> root->data << " with target" << target << endl;
	if(root->data == target) {
		//isi ko delete krna h 
		//4 cases 
		if(root->left == NULL && root->right == NULL) {
			//leaf node
			//delete root;
			return NULL;
		}
		else if(root->left == NULL && root->right != NULL) {
			Node* child = root->right;
			//delete root;
			return child;
		}
		else if(root->left != NULL && root->right == NULL) {
			Node* child  = root->left;
			//delete root;
			return child;
		}
		else {
			//both child
			//find inorder predecessor inb left subtree
			int inorderPre = largest_iterative(root->left);
			//replace root->data value with inorder predecessor
			root->data = inorderPre;
			//delete inorder predecessor from left subtree
			root->left = deleteNodeInBST(root->left,inorderPre);
			return root;
			
		}
		
	}
	else if(target > root -> data) {
		//right jana chahiye
		root->right =  deleteNodeInBST(root->right, target);
	}
	else if(target < root->data) {
		//left jana chahioye
		root->left = deleteNodeInBST(root->left, target);
	}
	return root;
}

bool validate_bst(Node *root){
    if(!root)return true;

    if(root->left->data < root->data || root->left ==NULL){
        return true;
    }else return false;
    if(root->right->data > root->data || root->right ==NULL){
        return true;
    }else return false;
    bool left_ans=validate_bst(root->left);
    bool right_ans=validate_bst(root->right);

    return left_ans || right_ans;
}

void Bst_to_Dll(Node * root,Node* &head){
    if(!root) return;

    Bst_to_Dll(root->right,head);
    root->right=head;
    if(head!=NULL) head->left=root;
    head=root;
    Bst_to_Dll(root->left,head);
}

void print_ll(Node* head){

    Node * temp= head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    cout<<endl;
}
Node* Dll_to_Bst(Node* &head,int n){
    if(n<=0 || head==NULL) return NULL ;

    Node* left_ans=Dll_to_Bst(head,n-1-n/2);

    Node* root= head;
    
    root->left=left_ans;
    head=head->right;

    root->right=Dll_to_Bst(head,n/2);

    return root;
}
int main(){
    Node *root=NULL;
    create_Bstree(root);
    Level_ordered_traversal(root);
    // 10 20 5 11 17 2 4 8 6 25 15 
    // 10 20 5 11 17 2 4 8 6 25 15 94 74 101 47 22 25 8 1 37

    // Level_ordered_traversal(root);

    // cout<<(search_bst(root,15));
    // jar 1 ala tr samjaycha true ahai mnje ki element present a 
    // or false mnje elemnt nhi mnje 0

    // ---------largest node
    // cout<<largest_iterative(root)<<endl;
    // // ---------smallest node
    // cout<<smallest_iteration(root)<<endl;

    //cout<<validate_bst(root)<<endl;

   //    converting to bst

   Node *head=NULL;
   Bst_to_Dll(root,head);
   print_ll(head);

   root=Dll_to_Bst(head,11);
   Level_ordered_traversal(root);
}