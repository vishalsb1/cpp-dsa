#include<iostream>
using namespace std;

// queue implimentation using array

class QUEUE{
  public:
    int *arr;
    int size;
    int front;
    int rare;

    QUEUE(int size){
       arr=new int[size];
       this->size=size;
       this->front=-1;
       this->rare=-1;
    }

    // push opertion
    void push(int data){
        if(rare==size-1){
            cout<<"Cannot push coz {overflow } satisfied";
            return;
        }
        else if(front=-1 && rare==-1){
            rare++;
            front++;
            arr[rare]=data;
        }else{
            // normal condiiton
            rare++;
            arr[rare]=data;
        }
    }
    // pop
    // 3 cases 1st-> underflow , 2nd ->single element , 3rd-> normal case
    void pop(){
        if(front==-1 && rare==-1){
            cout<<"cannot pop coz queue is emtty"<<endl;
            return;
        }
        else if(front==rare){
            // single element case

            // pop
            arr[front]=-1;
            front=-1;
            rare=-1;
        }else{
            arr[front]=-1;
            front++;
        }
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

class CQUEUE{
  public:
    int *arr;
    int size;
    int front;
    int rare;

    CQUEUE(int size){
       arr=new int[size];
       this->size=size;
       this->front=-1;
       this->rare=-1;
    }

    // push opertion
    void push(int data){
        if((front==0 && rare==size-1 ) ||  rare==front-1){
            cout<<"Cannot push coz {overflow } satisfied";
            return;
        }
        else if(front==-1 && rare==-1){
            rare=0;
            front=0;
            arr[rare]=data;
        }
        else if(rare==size-1 && front!=0){
            // circular case
            rare=0;
            arr[rare]=data;
        }
        else{
            // normal condiiton
            rare++;
            arr[rare]=data;
        }
    }
    // pop
    // 3 cases 1st-> underflow , 2nd ->single element , 3rd-> normal case
    void pop(){
        if(front==-1 && rare==-1){
            cout<<"cannot pop coz queue is emtty"<<endl;
            return;
        }
        else if(front==rare){
            // single element case

            // pop
            arr[front]=-1;
            front=-1;
            rare=-1;
        }
        else if (front==size-1){
            // circular case
            arr[front]=-1;
            front=0;
        }
        else{
            arr[front]=-1;
            front++;
        }
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

 
int main(){
    CQUEUE q(5);
    q.push(6);
    q.push(46);
    q.push(66);
    q.push(96);
    q.push(96);
    // q.push(96);
    q.pop();
    q.push(8);
    q.print();
}