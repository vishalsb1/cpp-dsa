#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverse_first_k_elements(queue<int> &q,int k){
    stack<int> st;
    int n=q.size();
    
    int i=0;
    while(i!=k){
        st.push(q.front());
        q.pop();
        i++;
    }
    while (!st.empty()){
        q.push(st.top());
        st.pop();
    } 

    for(int i=0;i<n-k;i++){
        int temp=q.front();
        q.pop();
        q.push(temp);
    }   
}
void print( queue <int> qu){
    while(!qu.empty()){
        cout<<qu.front();
        qu.pop();
    }
}
int main(){
    queue<int> qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    cout<<"before->";
    print(qu);
    cout<<endl;
    reverse_first_k_elements(qu,2);
    cout<<"after->";
    print(qu);
    cout<<endl;
    return 0;
}