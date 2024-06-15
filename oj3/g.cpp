#include <stdio.h>
#include <queue>

using namespace std;
typedef struct tree
{
    int key;
    int turn;
    tree *left;
    tree *right;
}tree;

tree *Insert(tree *bst,tree *s);
tree A[1001];
int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        int x,max=0;
        int result;
        A[1].turn=1;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d",&x);
            A[i].turn=1;
            A[i].key=x;
            A[i].left=NULL;
            A[i].right=NULL;
            if(i>1) Insert(&A[1],&A[i]);
            if(A[i].turn>max) max=A[i].turn;
        }
        result=max-n;
        printf("%d\n",result);
    }
    
    return 0;
}
tree *Insert(tree *bst,tree *s){
    if(bst==NULL) bst=s;
    if(bst->key<s->key){
        s->turn=s->turn*2+1;
        bst->right=Insert(bst->right,s);
    }
    if(bst->key>s->key){
        s->turn=s->turn*2;
        bst->left=Insert(bst->left,s);
    }

    return bst;
}