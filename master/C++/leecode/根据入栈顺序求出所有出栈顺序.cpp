#include<iostream>
#include<stack>
#include<queue>
// #include<algorithm>

using namespace std;
int n;
char a[5000];

void dfs(queue<char> b,int n,stack<int> st,queue<char> out)
{
    if(n<=0||(b.empty()&&st.empty()&&out.empty())){
        return;
    }

    if(out.size() == n){
        while(!out.empty()){
            cout<<out.front()<<" ";
            out.pop();
        }
        cout<<endl;
        return;
    }

    stack<int> stcopy = st;
    queue<char> outcopy = out;

    if(!st.empty()){
        out.push(st.top());
        st.pop();
        dfs(b,n,st,out);
    }


    if(!b.empty()){
        stcopy.push(b.front());
        b.pop();
        dfs(b,n,stcopy,outcopy);
    }
}

int main()
{
    cin>>n;
    queue<char> b,out;
    stack<int>st;

    for (int i=0;i<n;i++){
        cin>>a[i];
        b.push(a[i]);

    }

    dfs(b,n,st,out);
    return 0;
}