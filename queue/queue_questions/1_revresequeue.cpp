#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void revrse_queue(queue<int> &qu){
    stack<int> st;
    while(!qu.empty()){
        st.push(qu.front());
        qu.pop();
    }
    while(!st.empty()){
        qu.push(st.top());
        st.pop();
    }
}
void reverse_queue_r(queue<int> &qu){
    if(qu.empty()){
        return ;
    }
    int top1=qu.front();
    qu.pop();
    reverse_queue_r(qu);
    qu.push(top1);
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
    cout<<"after->";
    // revrse_queue(qu);
    reverse_queue_r(qu);
    print(qu);
    cout<<endl;
    return 0;
}