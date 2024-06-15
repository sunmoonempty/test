#include <bits/stdc++.h>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

typedef pair<int,int> PII;
priority_queue<PII,vector<PII>,greater<PII>> heap;
vector<int> ks;
vector<PII> distant[10001];
int hour[10001];


void Dijkstra();
int main(){
    int n,e,k;
    int u,v,w;
    int source;
    
    memset(hour,0x3f,sizeof(hour));
    
    scanf("%d %d %d",&n,&e,&k);
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&u,&v,&w);
        distant[u].emplace_back(v,w);
        distant[v].emplace_back(u,w);
    }
    for(int i=0;i<k;i++){
        scanf("%d",&source);
        distant[source].emplace_back(source,0);
        ks.push_back(source);
    }
    
    Dijkstra();
    
    for(int i=1;i<=n;i++){
        if(i!=n) printf("%d ",hour[i]);
        else printf("%d",hour[i]);
    }
    printf("\n");
    return 0;
}
void Dijkstra(){
    for(int k:ks){
        hour[k]=0;
        heap.push(make_pair(0,k));
    }
    
    vector<bool> visit(10001,false);
    while(!heap.empty()){
        int u=heap.top().second;
        int time=heap.top().first;
        heap.pop();


        //if(visit[u])continue;
        //else visit[u]=true;

        if(time>hour[u]) continue;
        for(auto edge:distant[u]){
            int v=edge.first;
            int t=edge.second;
            if(hour[v]>hour[u]+t){
                hour[v]=hour[u]+t;
                heap.push(make_pair(hour[v],v));
            }
        }
    }
}