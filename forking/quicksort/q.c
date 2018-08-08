#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>



void quick(int a[],int left,int right,int n)
{
    int c=0;
    int i=left,j=right;
    int mid=(left+right)/2;

    while(i<=j)
    {

        while(a[i]<a[mid])
            i++;
        while(a[j]>a[mid])
            j--;

        if(i<=j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;

        }

    }
    int pid=vfork();
    if(pid==0)
    {
        if(left<j)
        {
        quick(a,left,j,n);
        }
        exit(0);
    }
    if(pid>0)
    {
        wait(NULL);
        if(i<right)
        {
        quick(a,i,right,n);
        }

    }





}


int main()
{
    int n;int i;
    printf("enter the no of elements");
    scanf("%d",&n);
    int a[n];
   printf("\nenter the elements");
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%10;
        printf("%d ",a[i]);
    }
    quick(a,0,n-1,n);
    for(i=0;i<n;i++)
        printf("\n%d",a[i]);

    return 0;
}
