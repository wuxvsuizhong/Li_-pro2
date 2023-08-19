#include <stdio.h>
struct note {
    int x;  //横坐标
    int y;  //纵坐标
};

int main(){
    struct note que[2501];
    int head,tail;
    int a[51][51];
    int book[51][51]={0};
    int i,j,k,sum,n,m,startx,starty,tx,ty;
    // 上下左右四个方向
    int next[4][2] = {
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}};

    scanf("%d %d %d %d",&n,&m,&startx,&starty);

    for ( i = 1; i <=n; i++)
        for(j = 1;j<=n;j++)
            scanf("%d",&a[i][j]);
    
    head = 1;
    tail = 1;

    que[tail].x = startx;
    que[tail].y = starty;
    tail++;
    book[startx][starty] = 1;
    sum = 1;

    // 队列不为空的时候循环，准确来说是head移动不到tail处那么循环就一直进行直到，head和tail相遇 
    while (head < tail)
    {
        for(k=0;k<=3;k++){
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];

            // 是否越界
            if(tx < 1 || tx > n || ty < 1 || ty >m)
                continue;
            
            if(a[tx][ty] > 0 && book[tx][ty] == 0){
                sum++;
                book[tx][ty] = 1;   //在book中标记当前坐标已经访问过
                que[tail].x = tx;
                que[tail].y = ty; 
                tail++;
            }
        }
        head++;  //head 向后移动，也就是类似访问队列的下一个元素
    }

    printf("%d\n",sum);
    getchar();getchar();
    return 0;

}
