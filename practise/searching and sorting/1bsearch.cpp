// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int Binary_Search(int *arr,int n,int target){
    int s=0;
    int e=n-1;


    while(s<=e){

        int mid=s+(e-s)/2;

        if(arr[mid]==target){
            return mid;
        }
        // jar arr[mid] hyo motha asla tr te apla terget left side la a so e=mid-1
        else if(arr[mid]>target){
            e=mid-1;
        }
        // jar arr[mid] (apan jetha thambloy(mid)) tyo target pekasha chota asla tr s=mid+1;
        else if(arr[mid]<target){
            s=mid+1;
        }
    }
    // jar bhetla ni tar return -1 or apan etha vegla pan kar tari condition main codee madhu taku shakto
    return -1;

}

//  answer storing pattern 

int find_first_occurance(int *arr,int n,int target){
  int s=0;
  int e=n-1;
  int ans=-1;

  while(s<=e){
    
    int mid=s+(e-s)/2;

    if(arr[mid]==target){
    //   yedha lakshat thevyach ki ju ans bheto tyo store karaycha
      ans=mid;
    //   atta answer jevha bhetla aplela mahit first occuance manje leftt la asti but mahiti nhi 
    //   left la aahai ka nhi te so store karaychi mng left la jachaa
      e=mid-1;
    }
    else if(arr[mid]>target){
        // hai same as binary search kahli pn
      e=mid-1;
    }
    else if(arr[mid]<target){
      s=mid+1;
    }
  }
  return ans;
  
}
int find_last_occurance(int *arr,int n,int target){
  int s=0;
  int e=n-1;
  int ans=-1;

  while(s<=e){

    int mid=s+(e-s)/2;

    if(arr[mid]==target){
    //   yedha lakshat thevyach ki ju ans bheto tyo store karaycha
      ans=mid;
    //   etha pn same but last occurance mnje sequence chya last la yeti so right la jacha 
    // so store ans go to right s+mid+1;
      s=mid+1;
    }
    else if(arr[mid]>target){
      e=mid-1;
    }
    else if(arr[mid]<target){
      s=mid;
    }
  }
  return ans;

}
int total_occurance(int *arr,int n,int target){
  int a= find_first_occurance(arr,n,target);
  int b=find_last_occurance(arr,n,target);
//   atta aplela mahiti first and last occurance tyat te elemnt ahait so last-first+1
  return b-a+1;
}
int main() {
    int arr[]={1,2,3,3,3,3,7,8,9};
    // int arr[]={1,2,3,4,5,7,8,9};
    int n=sizeof(arr)/sizeof(int);
    int target =3;


    // cout<< Binary_Search(arr,n,target);//etha jo phijel tyo gheycha target
    // cout<< find_first_occurance(arr,n,target)<<endl;//target=3 asnar etha
    // cout<< find_last_occurance(arr,n,target);//target=2 asnar etha - arr[]={1,2,3,3,3,3,7,8,9};
    cout<< total_occurance(arr,n,target);//target=3 asnar etha
    
    return 0;
}