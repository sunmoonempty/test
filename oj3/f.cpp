#include<bits/stdc++.h>
#include <string.h>
#include <math.h>
#include <queue>
using namespace std;

typedef struct tree
{
    int val;//数字
    int color;//颜色
    int size;//子树大小
    int bnum;//子树黑
    int wnum;//子树白
    int flag;//标志,1不是，0是，每个节点初始为0
    tree *left;//左子树
    tree *right;//右子树
}tree;

tree *Insert(tree *bst,tree *s);//插入并更新 size，sn
void count(tree *bst);//统计bum，wnum，确定flag
void result(tree *dfs);//找到满足flag=0，且size最大的点
void BFS(tree *bfs);
tree A[1005];

int cnt;
int max_size;
deque<int> re;
int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        int x;
        cnt=0;
        max_size=0;
        char s[1005];
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            A[i]={x,0,1,0,0,0,NULL,NULL};
            if(i>1) Insert(&A[1],&A[i]);
        }

        scanf("%s",s);
        //printf("%c",s[0]);
        for(int i=0;i<strlen(s);i++){
            A[i+1].color=(int)s[i]-'0';
        }
        count(&A[1]);
        result(&A[1]);
        sort(re.begin(),re.end());
        //printf("%d %d %d %d %d\n",A[1].bnum,A[1].wnum,A[1].flag,A[1].val,A[1].size);
        printf("%d\n",max_size);
        while(!re.empty()){
            x=re.front();
            if(cnt==0) printf("%d",x);
            else printf(" %d",x);
            cnt++;
            re.pop_front();
            if(re.empty()) printf("\n"); 
        }       
    }
    return 0;
}
tree *Insert(tree *bst,tree *s){
    if(bst==NULL) bst=s;
    if(bst->val<s->val){
        bst->size++;
        bst->right=Insert(bst->right,s);
    } 
    if(bst->val>s->val){
        bst->size++;
        bst->left=Insert(bst->left,s);
    } 
    return bst;
}
void count(tree *bst){
    if(bst!=NULL){
        if(bst->color==1) bst->wnum++;//本身颜色算上
        else bst->bnum++;

        if(bst->left){
            count(bst->left);
            bst->wnum+=bst->left->wnum;
            bst->bnum+=bst->left->bnum;
        }//加上左
        if(bst->right){
            count(bst->right);
            bst->wnum+=bst->right->wnum;
            bst->bnum+=bst->right->bnum;
        }//加上右
        
        if(abs(bst->wnum-bst->bnum)>1) bst->flag=1;//差大于1直接不是
        else{
            if(bst->left) bst->flag+=bst->left->flag;
            if(bst->right) bst->flag+=bst->right->flag;
            if(bst->flag>1) bst->flag=1;//大于1表示,左右至少一个不是,那么这个不是
        }
    }
}
void result(tree *dfs){
    if(dfs!=NULL){
        if(dfs->flag==0){
            if(dfs->size==max_size){
                re.push_back(dfs-A);
            }
            if(dfs->size>max_size){
                max_size=dfs->size;
                re.clear();
                re.push_back(dfs-A);
            }
        }
        else{
            result(dfs->left);
            result(dfs->right);
        } 
    }
}
