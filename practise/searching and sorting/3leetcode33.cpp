#include <iostream>
using namespace std;

class Solution {
public:
    int find_pivot(vector<int> arr){
        int s=0;
        int e=arr.size()-1;
        int mid=s+(e-s)/2;

        while(s<=e){
            if(s==e)
                return s;
            if(mid+1<arr.size() && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(mid-1>=0 && arr[mid]<arr[mid-1] ){
                return mid-1;
            }
            else if(arr[mid]<arr[s]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
    int binary_search(vector<int> arr,int s,int e,int target){

        int mid=s+(e-s)/2;

        while(s<=e){
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
    int search(vector<int>& arr, int target) {
        int pivo_index=find_pivot(arr);
        cout<<pivo_index;
        int ans;

        if(target>=arr[0]&& target<=arr[pivo_index]){
            ans=binary_search(arr,0,pivo_index,target);
        }
        else{
            ans=binary_search(arr,pivo_index+1,arr.size()-1,target);
        }
        return ans;
    }
};