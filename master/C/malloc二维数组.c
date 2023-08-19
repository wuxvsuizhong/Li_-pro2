#include<stdio.h>
#include<stdlib.h>

int main()
{
    int m,n;
    m=5;
    n=5;

    // 方式1：malloc二维数组

    int **p = (int **)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        p[i] = (int *)malloc(n*sizeof(int));
    }


    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            p[i][j] = i*j;
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("p[%d][%d]:%d\n",i,j,p[i][j]);
        }
    }

    for(int i=0;i<m;i++) free(p[i]);
    free(p);

    printf("------------------------\n");
    // 方式2：malloc二维数组
    // 这种方式只要一个语句即可申请二位数组，释放也只需要一次free(p2)即可
    // 缺点是在申请数组时候大小只能写常量,如 int (*P2)[5]，无法根据具体需求申请响应大小的内存
    int (*p2)[5] = (int (*)[5])malloc(sizeof(int)*5*5);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            p2[i][j] = i*j;
        }
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("p2[%d][%d]:%d\n",i,j,p2[i][j]);
        }
    }

    free(p2);

    return 0;

}