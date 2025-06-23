#include <stdio.h>
typedef int keytype;
typedef float othertype;
typedef struct {
	keytype key;
	othertype otherfields;
}recordtype;	
//doi cho
void swap(recordtype *x,recordtype *y){
	recordtype temp;
	temp = *x;
	*x=*y;
	*y=temp;
}
//Insert_Sort
void Insert_Sort(recordtype A[], int n){
	int i,j;
	for ( i = 1; i<=n-1;i++){
		j=i;
		while((j > 0) &&(A[j].key < A[j-1].key)){
			swap(&A[j],&A[j-1]);
			j--;
		}
	}
}
void Read(recordtype A[], int *n){
	FILE *f;
	f = fopen("data.txt","r");
	int i = 0;
	if (f!=NULL){
		while (!feof(f)){
			fscanf(f,"%d%f",&A[i].key,&A[i].otherfields);
			i++;
		}
	}
	else printf("Loi mo file\n");
	fclose(f);
	*n = i;
}
void Print(recordtype A[], int n){
	int i;
	for ( i =0 ; i<n;i++){
		printf("%3d %5d %8.2f\n",i+1,A[i].key,A[i].otherfields);
	}
}
int main(){
	recordtype A[100];
	int n;
	printf("Thuat toan Insert_Sort\n");
	Read(A,&n);
	printf("Danh sach chua sap xep: \n");
	Print(A,n);
	Insert_Sort(A,n);
	printf("Danh sach sau khi sap xep: \n");
	Print(A,n);
	return 0;
}
