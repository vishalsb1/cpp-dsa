// -------------implementation-----------------------
#include <bits/stdc++.h>
using namespace std;
class Heap{
    public:
      int arr[401];
      int size;

    Heap(){
        arr[0]=-1;
        size=0;
    }

    void insert_element(int val){
        size+=1;
        // atta hya index vla insert
        int index=size;
        arr[index]=val;

        while(index > 1){
            int parent_index=index/2;

            // comparision if parent val is big or small then current value (arr[index])
            if(arr[index] > arr[parent_index]){
                // jar current index val elkement motha asla parent chya value peksha so swap
                swap(arr[index],arr[parent_index]);
                index=parent_index;
            }
            else{
                break;
            }
        }
    }

    // deleting element (top element)

    void delete_element(){

        arr[1]=arr[size];
        size--;

        int index=1;
        while(index < size){

            int left_index=2*index;
            int right_index=2*index+1;

            int largest=index;

            if(left_index < size && arr[largest] < arr[left_index]) largest=left_index;
            if(right_index < size && arr[largest] < arr[right_index]) largest=right_index;

            if(largest==index){
                return;
            }
            else{
                swap(arr[largest],arr[index]);
                index=largest;
            }
            
        }
    }


};

void heapify(int arr[],int n,int i){
    int index=i;
    int left=2*index;
    int right=2*index+1;

    int largest=index;

    if(left <= n && arr[largest]<arr[left]) largest=left;
    if(right<= n && arr[largest]<arr[right]) largest=right;

    if(largest!=index){
        swap(arr[largest],arr[index]);
        index=largest;
        heapify(arr,n,index);
    }

}

void build_heap(int arr[], int n){

    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
}

void print1(Heap h){

    for(int i=0;i<=h.size;i++){
        cout<<h.arr[i]<<"  ";
    }cout<<endl;
}
int main(){

    // Heap h;
    // h.arr[0]=-1;
    // h.arr[1]=100;
    // h.arr[2]=50;
    // h.arr[3]=60;
    // h.arr[4]=40;
    // h.arr[5]=45;

    // h.size=5;
    // h.insert_element(100);
    // h.insert_element(50);
    // h.insert_element(60);
    // h.insert_element(40);
    // h.insert_element(45);
    // cout<<" Printing heap elements "<<endl;
    // print1(h);
    // h.ins;ert_element();
    // h.insert_element(110);




    // deleting top 

    // h.delete_element();
    // print1(h);


    // -------------heapify-------------

    int arr[]={-1,23,42,4,5,64,32,44};

    build_heap(arr,(sizeof(arr)/sizeof(int))-1);

    for(int i=0 ; i< 8; i++){
        cout<<arr[i]<<" ";
    }

}