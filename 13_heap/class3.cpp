#include<bits/stdc++.h>
using namespace std;
// 1
// data structure that stores three data variables 
class ds_3{
    public:
     int data;
     int row;
     int col;

    ds_3(int data,int r,int c){
        this->data=data;
        this->row=r;
        this->col=c;
    }

};

// classcomparator
class cmp{ 
    public:
      bool operator()(ds_3*a,ds_3* b){
        return a->data > b->data;
      }
};
vector<int> MergeKSortedArr(vector<vector<int>>arr,int row, int col){
    priority_queue<ds_3* ,vector<ds_3*> , cmp> minpq;

    for(int i=0;i<row;i++){
        // pushing the data present at index0 of every row and also tthe row ans the column
        ds_3* temp=new ds_3(arr[i][0],i,0);
        minpq.push(temp);
    }
    vector<int> ans;

    while(!minpq.empty()){
        ds_3* temp=minpq.top();
        int tdata=temp->data;
        int trow=temp->row;
        int tcol=temp->col;

        // pop the top element
        minpq.pop();

        ans.push_back(tdata);
        if(tcol+1 < col){
            ds_3* temp2=new ds_3(arr[trow][tcol+1],trow,tcol+1);

            minpq.push(temp2);
        }
    }

    return ans;
}
// 2
// lik to the next question = https://leetcode.com/problems/merge-k-sorted-lists/submissions/1494213701/
int main(){
    
    vector<vector<int>> var={{2,3,4,5},{7,8,10,12},{13,55,90,95}};

    int row=3;
    int col=4;

    vector<int> ans=MergeKSortedArr(var,row,col);

    for( auto i : ans){
        cout<<i<<" ";
    }
    
    
    
    return 0;

}