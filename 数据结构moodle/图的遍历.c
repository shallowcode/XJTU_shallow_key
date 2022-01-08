#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int matrix[10][10];
int list[9];
int stack[10];
int cet=0;
int queue[10];
int start=1;
int end=1;
void dfs(int i){
    if(!list[i]){
        printf("%c",'A'+i);
        list[i]=1;
    }
    for (int j=0;j<9;++j){
        if(matrix[i][j]==1 && !list[j]){
            stack[cet++]=i;
            dfs(j);
            break;
        }
        if(j==8){
            if(!cet){
                return;
            }
            else{
                dfs(stack[--cet]);
            }
        }
    }
}

void bfs(int i){
    if(!list[i]){
        printf("%c",'A'+i);
        list[i]=1;

    }
    for (int j=0;j<9;++j){
        if(matrix[i][j]==1 && !list[j]){
            printf("%c",'A'+j);
            list[j]=1;
            queue[end++]=j;
        }
    }
    if(queue[start]==-1){
        return;
    }
    else{
        bfs(queue[start++]);
    }
}
int main(){
    for (int i=0;i<9;++i){
        for (int j=0;j<9;++j){
            scanf("%d",&matrix[i][j]);
        }
        list[i]=0;
    }
    dfs(0);
    printf("\n");
    queue[9]=-1;
    for (int i=0;i<9;++i){
        list[i]=0;
    }
    bfs(0);
}