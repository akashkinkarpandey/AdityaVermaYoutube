#include<stdio.h>
void bins(int a[],int n){
int f=0;
int j=n-1;
int i=0;
int res=-1;
while(j>=i){
int c=i+(j-i)/2;
int n=(c+1)%n;
int p=(c+n-1)%n;

if(a[c]<=a[n]&&a[c]<=a[p])
{
res=c;
break;

}
else if(a[i]<=a[c]){
i=c+1;
}
else if(a[c]<=a[j])
j=c-1;
}
printf("\n%d no of rotation ",res);

}
int main(){
int a[100];
int n;
printf("\nenter the size of an array:\t");
scanf("%d",&n);
int i;
for(i=0;i<n;i++)
{
printf("\nenter the index of array a[%d]-\t",i+1);
scanf("%d",&a[i]);
}
bins(a,n);
}
