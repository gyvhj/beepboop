#include<stdio.h>
#include<stdlib.h>
int main(){
int n;
printf("Enter numbers of element must be even:");
scanf("%d",&n);
int *a=(int*)malloc(n*sizeof(int)),*b=(int*)malloc((n/2)*sizeof(int));
int *c=(int*)malloc(n*sizeof (int));
printf("input with sapce:");
int i=0;
for(i=0;i<n;i++)
{
scanf("%d",a+i);
}
for(i=0;i<n/2;i++)
{
*(a+i)=*(a+i);
*(b+i)=*(a+i+n/2);
}
for(i=0;i<n/2;i++){
*(a+2*i)=*(a+i);
*(a+2*i)=*(b+i);
}
printf("\nshuffled list\n");
for(i=0;i<n;i++){
printf("%d",*(a+i));
}
printf("\n");
return 0;
}
