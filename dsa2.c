#include<stdio.h>
void ReverseArray(int arr[],int size){
int start= 0 ;
int end= size-1;
int temp;
while(start<end){
temp= arr[start];
arr[start]= arr[end];
arr[end]= temp;
start++;
end--;
}
}
int main(){
int size;
printf("Enter the size of the array:");
scanf("%d",&size);
int arr[size];
printf("Enter%d element the array:\n", size);
int i;
for( i =0 ; i<size; i++){
scanf("%d", &arr[i]);
}
printf("\n");
ReverseArray(arr,size);
printf("ReverseArray:");
for( i=0 ; i< size ;  i++){
printf("%d",arr[i]);
}
printf("\n");
return 0;
}

