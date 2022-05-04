#include<bits/stdc++.h>
#define ll long long
using namespace std;
int postfix(string s)
{
    stack<int>st;
    for(int i=0;i<s.length();++i)
    {
        if(s[i]==' ')
        continue;
        else if(isdigit(s[i]))   // if the character is integer then keep counting and evaluating number till space
        {
            int num=0;
            while(s[i]!=' '&&i!=s.length())
            {
                num=num*10+(int)(s[i]-'0');   // after + we are subtacting the ascii value of 0 from the character to get the actual integer
                i++;
            }
            i--;
            // cout<<num<<endl;
            st.push(num);   // after evaluating number push it into the stack
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
        {
            if(s[i]=='+')
            {
                int op1=st.top();
                st.pop();
                int op2=st.top();
                st.pop();
                st.push(op2+op1);  // we will evaluate the first pushed  value first i.e in stack the second one will be the first pushed after pop
            }
            else if(s[i]=='-')
            {
                int op1=st.top();
                st.pop();
                int op2=st.top();
                st.pop();
                st.push(op2-op1);   
            }
            else if(s[i]=='*')
            {
                int op1=st.top();
                st.pop();
                int op2=st.top();
                st.pop();
                st.push(op2*op1);   
            }
            else if(s[i]=='/')
            {
                int op1=st.top();
                st.pop();
                int op2=st.top();
                st.pop();
                st.push(op2/op1);   
            }
            else if(s[i]=='^')
            {
                int op1=st.top();
                st.pop();
                int op2=st.top();
                st.pop();
                st.push(pow(op2,op1));   
            }
            
        }
        else continue;

    }
    
    return st.top();
}
int main()
{
    string s;
    getline(cin,s);
    cout<<postfix(s);

}

// the idea behind solving this peoblem is to traverse the string from left to right and keep pushing element in the stack if 
// the element is integer and when we got the operator then pop two elements from the stack and apply the operation on both digits 
// and then push the result in the stack and after coming out of the loop return the top most element of the stack
// at last we got only one element in the stack only so simply return it