#include<bits/stdc++.h>
using namespace std;
int ICP(char token);
int ISP(char token);

int main(void){
    string A,B,Input;
    int inputNum=0;
    cin>>inputNum;
    cin.ignore();
    stack<string> output;
    for(int i=0;i<inputNum;i++){
        A="",B="",Input="";
        getline(cin,Input);
        int j=0;
        for(j=0;j<Input.length();j++){
            if(Input[j]!=' '){
                A+=Input[j];
            }
            else{
                break;
            }
        }
        for(++j;j<Input.length();j++){
            B+=Input[j];
        }
        string temp="";
        stack<string> postfix;
        for(j=0;j<B.length();j++){
            if(B[j]!='+'&&B[j]!='-'&&B[j]!='*'&&B[j]!='/'&&B[j]!='('&&B[j]!=')'){
                temp+=B[j];
            }
            else{
                if(postfix.empty()){
                    string s="";
                    s+=B[j];
                    postfix.push(s);
                }
                else{
                    char t=postfix.top()[0];
                    if(B[j]==')'){
                        while(postfix.top()!="("){
                            temp+=postfix.top();
                            postfix.pop();
                        }
                        postfix.pop();
                    }
                    else{
                        while(ICP(B[j])<=ISP(t) && !postfix.empty()){
                            temp+=postfix.top();
                            postfix.pop();
                            if(!postfix.empty()){
                                t=postfix.top()[0];
                            }
                        }
                        string s="";
                        s+=B[j];
                        postfix.push(s);
                    }
                }  
            }
        }
        while(!postfix.empty()){
            temp+=postfix.top();
            postfix.pop();
        }
        //cout<<temp<<"\n";
        temp=A+temp;
        //cout<<temp<<"\n";
        for(j=0;j<temp.length();j++){
            if(temp[j]!='+'&&temp[j]!='-'&&temp[j]!='*'&&temp[j]!='/'){
                string s;
                s+=temp[j];
                postfix.push(s);
            }
            else{
                string first=postfix.top();
                postfix.pop();
                string second=postfix.top();
                postfix.pop();
                string s="(";
                s+=second+temp[j]+first;
                s+=")";
                postfix.push(s);
            }
        }
        temp=postfix.top();
        postfix.pop();
        //cout<<temp<<"\n";
        // for(j=0;j<B.length();j++){
        //     temp+=B[j];
        // }
        string reverse="";
        for(j=temp.length()-1;j>=0;j--){
            if(temp[j]=='('){
                reverse+=")";
            }
            else if(temp[j]==')'){
                reverse+="(";
            }
            else{
                reverse+=temp[j];
            }
        }
        
        for(j=0;j<reverse.length();j++){
            if(reverse[j]!='+'&&reverse[j]!='-'&&reverse[j]!='*'&&reverse[j]!='/'&&reverse[j]!='('&&reverse[j]!=')'){
                string s="";
                s+=reverse[j];
                output.push(s);
            }
            else{
                if(postfix.empty()){
                    string s="";
                    s+=reverse[j];
                    postfix.push(s);
                }
                else{
                    char t=postfix.top()[0];
                    if(reverse[j]==')'){
                        while(postfix.top()!="("){
                            output.push(postfix.top());
                            postfix.pop();
                        }
                        postfix.pop();
                    }
                    else{
                        while(ICP(reverse[j])<=ISP(t) && !postfix.empty()){
                            output.push(postfix.top());
                            postfix.pop();
                            if(!postfix.empty()){
                                t=postfix.top()[0];
                            }
                        }
                        string s="";
                        s+=reverse[j];
                        postfix.push(s);
                    }
                }  
            }
        }
        while(!postfix.empty()){
            output.push(postfix.top());
            postfix.pop();
        }

        while(!output.empty()){
            cout<<output.top();
            output.pop();
        }
        cout<<"\n";
    }
    return 0;
}

int ICP(char token){
    if(token=='('){
        return 3;
    }
    else if(token=='*'||token=='/'){
        return 2;
    }
    else{
        return 1;
    }
}
int ISP(char token){
    if(token=='('){
        return 0;
    }
    else if(token=='*'||token=='/'){
        return 2;
    }
    else{
        return 1;
    }
}