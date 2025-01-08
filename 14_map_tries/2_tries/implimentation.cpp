#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
       char data;
       TrieNode* children[26];
       bool flag;

    TrieNode(char ch){
        this->data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        this->flag=false;
    }
};

void insert_word(TrieNode*root,string word1){
    // base case 
    if(word1.length()==0){
        // if the word is completed just mark the last letter as flag true
        root->flag=true;
        return;
    }

    char ch=word1[0];
    int index=ch-'A';
    TrieNode* child;

    // the current char is present the just iterate and inert
    if(root->children[index]!=NULL){
        child=root->children[index];
    }
    else{
        // not present als tar just create and go further 
        child=new TrieNode(ch);
        root->children[index]=child;
    }

    // ek case zala baki recurssion
    insert_char(child,word1.substr(1));
}

bool search(TrieNode*root,string word1){
    // base case 
    if(word1.length()==0){
        // if the word is completed just mark the last letter as flag true
        return true;
    }

    char ch=word1[0];
    int index=ch-'A';
    TrieNode* child;

    // the current char is present the just iterate and inert
    if(root->children[index]!=NULL){
        child=root->children[index];
    }else{
        return false;
    }
    return search(child,word1.substr(1));

}
// TrieNode* search_for_del(TrieNode*root,string word1){
//     // base case 
//     if(word1.length()==0){
//         // if the word is completed just mark the last letter as flag true
//         return root;
//     }

//     char ch=word1[0];
//     int index=ch-'A';
//     TrieNode* child;

//     // the current char is present the just iterate and inert
//     if(root->children[index]!=NULL){
//         child=root->children[index];
//     }else{
//         return NULL;
//     }
//     return search(child,word1.substr(1));

// }

// void delete_word(TrieNode*root,string word1){
//     TrieNode * temp=search_for_del(TrieNode*root,string word1);
//     int last_index=word1.length();
//     root->children[index]
    
// }
int main(){

    TrieNode* root=new TrieNode('-');// nnull inserrrt kelyat gat 
    insert_word(root,"vishal");
    insert_word(root,"viashali");
    insert_word(root,"varun");
    insert_word(root,"vivek");


    // if(search(root,"varunr")) cout<<"present";
    search(root,"varunr") ? cout<< "presentt" : cout<< "notpresent";
    return 0;
}