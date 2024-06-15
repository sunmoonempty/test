#include <iostream> 
#include <algorithm>

using namespace std;
struct Edge
{
    int u,v,w;
    bool operator<(const Edge &W)const
    {
        return w<W.w;
    }
}edges[20001];

int p[20001];
int find(int x);
int Kruskal(int m,int n);

int main(){
    int T,n,m;
    scanf("%d",&T);
    while(T--){
        int u,v,w;
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&w);
            edges[i]={u,v,w};
        }
        int t=Kruskal(m,n);
        if(t==-1) printf("impossible\n");
        else printf("%d\n",t);
    }
    return 0;
}
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int Kruskal(int m,int n){
    sort(edges,edges+m,[](const Edge &a,const Edge &b){return a.w>b.w;});
    for(int i=0;i<=n;i++) p[i]=i;
    int res=0,cnt=0,sum=0;
    for(int i=0;i<m;i++){
        int u=edges[i].u,v=edges[i].v,w=edges[i].w;
        sum+=w;
        u=find(u),v=find(v);
        if(u!=v){
            p[u]=v;
            res+=w;
            cnt++;
        }
    }
    if(cnt<n-1) return -1;
    return sum-res;
}