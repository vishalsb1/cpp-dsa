#include <bits/stdc++.h>
using namespace std;


int getKthSmallest(int arr[],int n, int k){

    priority_queue<int> pq;

    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i=k;i<n;i++){
        if(arr[i]<pq.top()){
            // deleting
            pq.pop();
            // heapifying 
            pq.push(arr[i]);
        }
    }
    // jo pq chya top la sto tyoch apla answer asto fkt samjun ghe ek 
    // thodkyat a patter gat a 
    return pq.top();
}
// greates kth element 
int getKthLargest(int arr[],int n, int k){

    priority_queue<int,vector<int>,greater<int>> mpq;

    for(int i=0;i<k;i++){
        mpq.push(arr[i]);
    }

    for(int i=k;i<n;i++){
        if(arr[i]>mpq.top()){
            // deleting
            mpq.pop();
            // heapifying 
            mpq.push(arr[i]);
        }
    }
    // jo pq chya top la sto tyoch apla answer asto fkt samjun ghe ek 
    // thodkyat a patter gat a 
    return mpq.top();
}
//  ------------------ is an bt a tree ------------------- 
// its not an heeap realatedc qyustion but folve it

pair<bool, int> solve(Node* root) {
        //base case
        if(root == NULL) {
                pair<bool,int> p = make_pair(true, INT_MIN);
                return p;
        }
        if(root->left == NULL && root->right == NULL)
        {
                //leaf node
                pair<bool,int> p = make_pair(true, root->data);
                return p;
        }

        pair<bool, int> leftAns = solve(root->left);
        pair<bool, int> rightAns = solve(root->right);

        if(leftAns.first == true &&
          rightAns.first == true &&
          root->data > leftAns.second &&
          root->data > rightAns.second) {
                  pair<bool, int> p =  make_pair(true, root->data);
                  return p;
          }
         
          else {
                  pair<bool, int> p =  make_pair(false, root->data);
                  return p;
          }
}


int main(){
    // max heap
    priority_queue<int> pq;
// baically the priority queue acts as an max heap 
    pq.push(10);
    pq.push(4);
    pq.push(6);
    pq.push(2);
    pq.push(8);
    pq.push(19);
    pq.push(15);
    cout<<pq.top();

    // for(int i=0 ;i<pq.size();i++){
    //     cout<<pq.at(i)<<" "
    // }
    cout<<endl;
    // min heap
    priority_queue<int,vector<int>,greater<int>> pqmin;
    pqmin.push(10);
    pqmin.push(4);
    pqmin.push(6);
    pqmin.push(2); 
    pqmin.push(8);
    pqmin.push(19);
    pqmin.push(15);
    cout<<pqmin.top();

    // ------------------ k th smallerst element -----------------
    cout<<endl;
    int arr[]={9,12,42,3,5,31,2,65,4,32};
    int size=sizeof(arr)/sizeof(int);

    int ans=getKthSmallest(arr,size,6);
    int ans_max=getKthLargest(arr,size,6);
    // finding the kth(6) largest elemnt 

    cout<<ans<<endl;
    cout<<ans_max;
    return 0;
}