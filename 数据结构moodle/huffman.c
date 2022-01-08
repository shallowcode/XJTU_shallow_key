#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int a[10];
    int ret;
    char letter;
    int wet;
    struct node* lchild;
    struct node* rchild;
}node;

typedef node* tree;
tree huffman[10];
int n;
tree head=NULL;
void shift(int i){
    tree temp=huffman[i];
    int head=huffman[i]->wet;
    char letter=huffman[i]->letter;
    while(1){
        int l=2*i;
        if((l<=n-1) && (huffman[l]->wet>huffman[l+1]->wet)) l++;
        if(l>n || head<huffman[l]->wet) break;
        huffman[i]=huffman[l];
        i=l;
    }
    huffman[i]=temp;
}
void insert(){
    tree a=huffman[1];
    huffman[1]=huffman[n--];
    shift(1);
    tree b=huffman[1];
    huffman[1]=huffman[n--];
    shift(1);
    tree temp=(tree)malloc(sizeof(node));
    temp->letter='-';
    temp->wet=a->wet+b->wet;
    if(a->wet<b->wet){
        temp->lchild=a;
        temp->rchild=b;
    }
    else{
        temp->lchild=b;
        temp->rchild=a;
    }
    if(n==0){
        head=temp;
        return;
    }
    huffman[++n]=huffman[1];
    huffman[1]=temp;
    shift(1);
}

void check(tree head){
    if(!head->lchild && !head->rchild){
        huffman[head->letter-'A'+1]=head;
    }
    if(head->lchild){
        for (int i=0;i<head->ret;++i){
            head->lchild->a[i]=head->a[i];
        }
        head->lchild->a[head->ret]=0;
        head->lchild->ret=head->ret+1;
        check(head->lchild);
    }
    if(head->rchild){
        for (int i=0;i<head->ret;++i){
            head->rchild->a[i]=head->a[i];
        }
        head->rchild->a[head->ret]=1;
        head->rchild->ret=head->ret+1;
        check(head->rchild);
    }
}
int main(){
    n=8;
    for (int i=1;i<=n;++i){
        tree temp=(tree)malloc(sizeof(node));
        temp->letter='A'+i-1;
        scanf("%d",&temp->wet);
        temp->lchild=NULL;
        temp->rchild=NULL;
        temp->a[0]=-1;
        temp->ret=0;
        huffman[i]=temp;
    }
    for (int i=4;i>=1;--i){
        shift(i);
    }
    while(n!=0){
        insert();
    }
    check(head);
    for (int i=1;i<=8;++i){
        for (int j=0;j<huffman[i]->ret;++j){
            printf("%d",huffman[i]->a[j]);
        }
    }
}