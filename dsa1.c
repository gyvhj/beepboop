#include<stdio.h>
int main(){
int arr[10];
int i,j,n=10;
printf("Enter the 10 element of array: \n");
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
for(i=2;i<n-2;i++){
arr[i]=arr[i+2];
}
printf(" Array after deleting 3rd and 6th element:\n");
for(i=0;i<n-2;i++){
printf("%d",arr[i]);
}
printf("\n");
printf("The 5th element of the resulting array:%d\n", arr[4]);
return 0;
}
