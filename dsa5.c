#include<stdio.h>
struct Term {
int coefficient;
int power;

};
void multiplyspacepolynomial(const struct Term* poly1,int size1,const struct Term* poly2,int size2,struct Term*result){
int index=0;
int i,j;
for(i=0;i<size1;i++){
for(j=0;j<size2;j++){
result[index].coefficient=poly1[i].coefficient*poly2[j].coefficient;
result[index].power=poly1[i].power+poly2[j].power;
index++;
}
}
}
void simplysparepolynomial(struct Term*poly,int size){
int i,j;
for( i=0;i<size;i++){
for( j=1+i;j<size; j++){
if(poly[i].power==poly[j].coefficient)
poly[j]=poly[size-1];
size--;
}
}
}
void printspacepolynomial(struct Term*poly1, int size){

int i;
for( i=1;i<size;i++){

printf("%d^%d",poly1[i].coefficient,poly1[i].power);
if(i<size-1){
printf("+");
}
}
printf("\n");
}
int main(){
struct Term poly1[]={{5,4},{3,2},{2,0}};
int size1=6;
struct Term poly2[]={{2,3},{1,1}};
int  size2 =4;

int maxResultsize=size1*size2;
struct Term result[maxResultsize];
multiplyspacepolynomial(poly1,size1,poly2,size2,result);
simplysparepolynomial(result,maxResultsize);

printf("polynomial at 1:");
printspacepolynomial(poly1,size1);
printf("polynomial at 2:");
printspacepolynomial(poly2,size2);
printf(" resultant polynomial :");
printspacepolynomial(poly1,maxResultsize);

return 0;
}




