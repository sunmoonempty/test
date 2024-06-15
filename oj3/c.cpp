#include <stdio.h>

typedef struct tree
{
    int key;
    int turn;
    tree *left;
    tree *right;
}tree;
tree A[1005];
tree *Insert(tree *bst,tree *s);
int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        int x;
        int result=1;
        A[1].turn=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            A[i].turn=1;
            A[i].key=x;
            A[i].left=NULL;
            A[i].right=NULL;
            if(i>1){
                Insert(&A[1],&A[i]);
                result+=A[i].turn;
            } 
        }
        printf("%d\n",result); 
    }
    return 0;
}
tree *Insert(tree *bst,tree *s){
    if(bst==NULL) bst=s;
    if(bst->key<s->key){
        bst->right=Insert(bst->right,s);
       s->turn++;
    }  
    if(bst->key>s->key){
        bst->left=Insert(bst->left,s);
        s->turn++;
    }  

    return bst;
}
    