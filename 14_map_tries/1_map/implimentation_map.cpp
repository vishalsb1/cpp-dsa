#include <bits/stdc++.h>
using namespace std;

// implemented an function to just check that an linked liat contains a loop or not

bool check_if_loop_in_ll(Node* root){
  unordered_map<Node*, bool> mapp1;

  Node* temp=root;

  while(temp!=NULLL){
    if(mapp1.find(temp)!=mapp1.end()){
      mapp1[temp]=true;
    }else{
      return true;
    }
  }
  return false;
}
int main() {
    // pair<string,int> p;
    // unordered_map<string,int> u_m;
    
    // p.first = "Mazda";    // Added semicolon
    // p.second = 1900;      // Added semicolon
    
    // u_m.insert(p);        // Correct insertion method
    // // OR u_m[p.first] = p.second;
    
    // cout << u_m["Mazda"] << endl;  // Correct way to access value
    
    // // iteration in map 

    // for (auto i : u_m){
    //     cout<<i.first<<"->"<<i.second<<endl;

        
    // }
 //  ---------------- mplimentation to calculate the number of each char in an word -------------------------------
 string str1="theruvanantpuram";

 unordered_map<char,int> freq;

 for(int i=0;i< str1.length();i++){
   char ch=str1[i];
   freq[ch]++;
 }
 for(auto i : freq){
  cout<< i.first <<"->"<<i.second <<endl;
 }


  return 0;

}