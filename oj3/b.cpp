#include <stdio.h>
int Mlag=0;
int Plag=0;
typedef struct Tree
{
    int val;
    Tree *left;
    Tree *right;
}Tree;

Tree* mereg(Tree *a,Tree *b);
void PreOrder(Tree* root){
	
	if (root != NULL)
	{
        if(Plag==0)
		printf("%d",root->val);
        else printf(" %d",root->val);
        Plag++;
        PreOrder(root->left);
        PreOrder(root->right);
        
	}
}
void MidOrder(Tree* root){
	if (root != NULL)
	{   
        MidOrder(root->left);
        if(Mlag==0)
        printf("%d",root->val);
        else printf(" %d",root->val);
        Mlag++;
        MidOrder(root->right);
        
	}
}

Tree A[101];
Tree B[101];
int main(){
    
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        int val,left,right;
        int max;
        Mlag=0,Plag=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&val,&left,&right);
            A[i].val=val;
            if(left==0) A[i].left=NULL;
            else A[i].left=&A[left];
            if(right==0) A[i].right=NULL;
            else A[i].right=&A[right];
        }
        
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d %d %d",&val,&left,&right);
            B[i].val=val;
            if(left==0) B[i].left=NULL;
            else B[i].left=&B[left];
            if(right==0) B[i].right=NULL;
            else B[i].right=&B[right];
        }
        
        mereg(&A[1],&B[1]);    
        PreOrder(&A[1]);
        printf("\n");
        MidOrder(&A[1]);
        printf("\n");
    }
    return 0;
}

Tree* mereg(Tree* a,Tree* b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    a->val+=b->val;
    a->left=mereg(a->left,b->left);
    a->right=mereg(a->right,b->right);

    return a;
}