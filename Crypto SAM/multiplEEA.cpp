#include<stdio.h>
#include<conio.h>
main()
{
 int n,b,x,r1,r2,t1,t2,q,r,t;
 printf("Enter values of n and b \n");
 scanf("%d %d",&n,&b);
 r1=n;
 r2=b;
 t1=0;
 t2=1;
 while(r2>0)
 {
  q=r1/r2;
  r=r1-q*r2;
  r1=r2;
  r2=r;
  t=t1-q*t2;
  t1=t2;
  t2=t;
 }
 if(r1==1)
  b=t1;
 printf("The value of multiplicative inverse is %d ", b);
}

