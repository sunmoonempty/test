#include <stdio.h>

void floyd(int n,int distant[205][205]);
void result(int n,int distant[205][205]);
int main(){
    int T,n,m;
    scanf("%d",&T);
    while(T--){
        int a,b;
        scanf("%d %d",&n,&m);
        int distant[205][205]={0};
        for(int i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            distant[a][b]=1;
        }

        floyd(n,distant);
        result(n,distant);
        if(T>0) printf("\n");
    }

    return 0;
}
void floyd(int n,int distant[205][205]){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
            if(distant[i][k]&&distant[k][j])
            distant[i][j]=1;
        }
    }
}
void result(int n,int distant[205][205]){
    for(int i=1;i<=n;i++){
        int best=0;
        int worst=0;

        for(int j=1;j<=n;j++){
            if(i!=j){
                if(distant[i][j]==1) worst++;
                if(distant[j][i]==1) best++;
            }
        }
        printf("%d %d\n",best+1,n-worst);
    }

}