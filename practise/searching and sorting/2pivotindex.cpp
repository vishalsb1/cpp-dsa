#include <iostream>
using namespace std;
int find_pivot(int *arr,int n){
  int s=0;
  int e=n-1;
  int mid=s+(e-s)/2;
  
  while(s<e){
    if(s==e)
      return s;

    // jeyavar thambloy to "mid" ani "mid+1" manje tya pudcha 
    // mid jar motha asla tr 
    if(arr[mid]>arr[mid+1]){
      return mid;
    //   corner case
    }
    else if(arr[mid]<arr[mid-1]){
    // khalichi line var but khalichya line cha pahila  
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
int main() {
  int arr[]={10,30,40,50,30,44};
  int n=sizeof(arr)/sizeof(int);

  int ans=find_pivot(arr,n);
  cout<<"index is -> " <<ans<<endl;
  cout<<endl;
  for(auto i:arr){
    cout<<i<<" ";
  }cout<<endl;
  for(int i=0;i<n;i++){
    if(i==ans)
       cout<<" ^ ";
    else
      cout<<"   "; 
  }
  
}