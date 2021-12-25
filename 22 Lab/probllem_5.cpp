/*Nadim Vai code*/
#include<bits/stdc++.h>
#define P(X) cout<<X<<endl;
#define P2(X,Y) cout<<X<<" "<<Y<<endl;
using namespace std;

bool isArithmetic(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch=='/')
        return true ;
    else
        return false ;
}

bool check(string s){
    stack<char>st;
    int cnt = 0, len = s.size();
    if(isArithmetic(s[len-1])) return 0;
    for(int i=0; i<len-1; i++){

        if(isArithmetic(s[i]) && ( s[i+1] == ')' || isArithmetic(s[i+1]))) return 0;
        if(s[i]=='(' && (s[i+1]==')'|| isArithmetic(s[i+1]))) return 0;
        if(s[i]==')' && (s[i+1]=='('|| isalpha(s[i+1]) || isdigit(s[i+1]))) return 0;

        if(s[i]=='(')st.push('(');
        if(s[i]==')'){
            if(st.empty()) return 0;
            st.pop();
        }
    }

    if(s[len-1]=='(') st.push('(');
    if(s[len-1]==')') {
        if(st.empty()) return 0;
        st.pop();
    }

    if(st.empty()) return 1;
    return 0;
}

int main()
{
    string s;
    cout<<"Enter a string: ";
    cin>>s;

    int len = s.size(), cnt = 0;
    for(int i=0; i<len; i++){
        if(isArithmetic(s[i]) || isalpha(s[i]) || isdigit(s[i]) || s[i]=='(' || s[i]==')') cnt++;
        
    }

    //cout<<len<<" "<<cnt<<endl;
    if(len != cnt) {
        cout<<"Output: INVALID\n";
        return 0;
    }

    if(check(s)) cout<<"Output: VALID\n";
    else cout<<"Output: INVALID\n";

    return 0;
}
