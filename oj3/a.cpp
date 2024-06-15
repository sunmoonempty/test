#include <iostream>
#include <queue>
#include <cstdio> 

using namespace std;
//左大右小
priority_queue<int> le;
priority_queue<int ,vector<int>,greater<int>> ri;

void popn();
void pushn(int n);

int main(){
    int n;
    char s[8];
    while(scanf("%s",&s)!=EOF){
        if(s[2]=='s'){
            scanf("%d",&n);
            pushn(n);
        }
        if(s[2]=='p'){
            popn();
        }
    }

    return 0;
}
void popn(){
    printf("%d\n",le.top());
    le.pop();
    if(le.size()>ri.size()+1){
        ri.push(le.top());
        le.pop();
    }
    if(ri.size()>le.size()){
        le.push(ri.top());
        ri.pop();
    }
}
void pushn(int n){
    if(le.empty()||n<le.top()) le.push(n);
    else ri.push(n);
    if(le.size()>ri.size()+1){
        ri.push(le.top());
        le.pop();
    }
    if(ri.size()>le.size()){
        le.push(ri.top());
        ri.pop();
    }
}
