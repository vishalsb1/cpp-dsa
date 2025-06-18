#include<bits/stdc++.h>
using namespace std;

class Conversions{

public:
    string exp_string;
    int index=0;
    string ans;
    stack<char> st;

    Conversions(string exp_string){
        this->exp_string=exp_string;
        ans.clear();
        index=0;
    }

    int priority(char ch){
        if(ch == '^') return 3;
        else if(ch=='*' || ch=='/') return 2;
        else if(ch=='+'|| ch=='-') return 1;
        return -1;
    }

    void infix_2_postfix(){
        string temp=exp_string;
        
        while(index<temp.length()){
            // if character then push
            char c=temp[index];
            if((c>='A' && c<='Z') ||(c>='a' && c<='z') || (c>='0' && c<='9')){
                ans+=c;
            }
            // if its an opening bracket
            else if(c=='(') st.push('(');
            else if(c==')'){

                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
                // this pop is for the closing braket
            }
            else{
                // its an definanitely an operator
                // but check the priority of the special symbol
                while(!st.empty() && (priority(c)<=priority(st.top()))){
                    ans+=st.top();
                    st.pop();
                }
                st.push(c);
            }
            index++;
        }
        // no when the given str (temp) ends but stack is not empty
        // then push them to ans

        while(!st.empty()){

            ans+=st.top();
            st.pop();
        }
        cout<<ans<<endl;
    }

    void infix_2_prefix(){
        string temp=exp_string;
        
        reverse(temp.begin(),temp.end());
        
        // now same code for infix to postfix but light changes
        while(index<temp.length()){
            // if character then push
            char c=temp[index];
            if((c>='A' && c<='Z') ||(c>='a' && c<='z') || (c>='0' && c<='9')){
                ans+=c;
            }
            // if its an opening bracket
            else if(c==')') st.push(c);
            else if(c=='('){
                
                while(!st.empty() && st.top()!=')'){
                    ans+=st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
                // this pop is for the closing braket
            }
            else{
                // its an definanitely an operator
                // but check the priority of the special symbol
                if(c=='^') {

                    while(!st.empty() && (priority(c)<=priority(st.top()))){
                        ans+=st.top();
                        st.pop();
                    }
                }
                else{
                  while(!st.empty() && (priority(c)<priority(st.top()))){
                    ans+=st.top();
                    st.pop();
                }  
                }
                st.push(c);
            }
            index++;
        }
        // no when the given str (temp) ends but stack is not empty
        // then push them to ans
        
        while(!st.empty()){
            
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }

    void postfix_2_infix(){
        string temp=exp_string;
        stack<string>st1;
        while(index<temp.length()){
            char c=temp[index];

            if((c>='A' && c<='Z') ||(c>='a' && c<='z') || (c>='0' && c<='9')){
                st1.push(string(1, c));
            }
            else{
                if (st1.size() < 2) {
                    cout << "Invalid postfix expression!" << endl;
                    return;
                }
                string t1=st1.top(); st1.pop();
                string t2=st1.top(); st1.pop();

                st1.push("(" + t2 + string(1, c) + t1 + ")");
            }
            index++;
        }      
        ans=st1.top();
        cout<<ans<<endl;
    }
    void prefix_2_infix(){
        string temp=exp_string;
        stack<string>st1;
        int i=temp.size();
        while(i>=0){
            char c=temp[index];

            if((c>='A' && c<='Z') ||(c>='a' && c<='z') || (c>='0' && c<='9')){
                st1.push(string(1, c));
            }
            else{
                if (st1.size() < 2) {
                    cout << "Invalid postfix expression!" << endl;
                    return;
                }
                string t1=st1.top(); st1.pop();
                string t2=st1.top(); st1.pop();

                st1.push("(" + t1 + string(1, c) + t2 + ")");
            }
            i--;
        }      
        ans=st1.top();
        cout<<ans<<endl;
    }

};


int main(){

    // Conversions cv("a+b*(c^d-e)");
    // cv.infix_2_postfix();
    // Conversions cv1("a+b*(c^d-e)");
    // cv1.infix_2_prefix();
    // Conversions cv("abcd^e-*+");
    // cv.postfix_2_infix();
    Conversions cv("*+pq-mn");
    cv.prefix_2_infix();
    return 0;
}