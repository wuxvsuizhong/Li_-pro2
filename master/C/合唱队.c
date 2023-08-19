#include<stdio.h>
#include<string.h>

int main()
{
    int n,row[3000],Max;
    char lmax[3000],rmax[3000];
    while(scanf("%d",&n) != EOF)
    {
        memset(lmax,0,3000);
        memset(rmax,0,3000);
        Max = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&row[i]);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if (row[i] < row[j] && lmax[i] < lmax[j] + 1)
                    lmax[i] = lmax[j]+1;
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(row[j] > row[i] && rmax[i] < rmax[j] +1 )
                    rmax[i] = rmax[j]+1;
            }
        }

        for(int i=0;i<n;i++){
            int tmp = lmax[i] + rmax[i]-1;
            if(Max < tmp) Max = tmp;
        }

        printf("%d\n",n-Max);
    }
    
    return 0;
}