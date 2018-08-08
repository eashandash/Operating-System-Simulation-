#include <stdio.h>

//----------->BubbleSort------------->//

void BubbleSort(int a[],int n)
{
  int i,j,temp;
  for(i=0;i<n;i=i+1)
  {
    for(j=0;j<n-1-i;j=j+1)
    {
      if(a[j]>=a[j+1])
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
   
}

int main(int argc, char const *argv[])
{
  int n;

  printf("Enter the value of n(size of array)\n");
  scanf("%d",&n);

  int a[n];

  //----------->BubbleSort------------->//

  printf("Enter the numbers\n");
  for(int i=0;i<n;i=i+1)
    scanf("%d",&a[i]);

  printf("The entered numbers are: ");

  for(int i=0;i<n;i=i+1)
    printf("%d ",a[i]);

  printf("\n");

  BubbleSort(a,n);

  printf("The final array obtained after BubbleSort is:");

  for(int i=0;i<n;i=i+1)
    printf("%d ",a[i]);

  printf("\n");

return 0;
}