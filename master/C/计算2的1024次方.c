#include<stdio.h>
#include<string.h>

void nPowerOfTwo(int n,char *res)
{
  int i,length,j,num,carry;
  for(i=0;i<n;i++){
    carry = 0;
    for(j=0;j<strlen(res);j++){
      num = res[j] - '0';
      num = (num <<1) + carry;
      carry = num/10;
      res[j] = num%10+'0';
    }
    if(carry > 0)
      res[j] = carry + '0';
  }

  // reverse(res);
}

void main()
{
  char s[1024]={1};
  nPowerOfTwo(2,s);
  printf("%s\n",s);
}