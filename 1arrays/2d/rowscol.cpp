#include<iostream>
using namespace std;
bool linearsearch(int arr[][3],int size,int target){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(arr[i][j]==target){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    // column wise 
    cout<<"column wise"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
    // row wise 
    cout<<"row wise"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<linearsearch(arr,3,5)<<endl;
    return 0;
}