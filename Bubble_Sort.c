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
//Bubble_sort
void Bubble_Sort(recordtype A[],int n){
	int i,j;
	for (i = 0; i<= n-2;i++){
		for (j = n-1 ; j>= i+1;j--){
			if (A[j].key < A[j-1].key){
				swap(&A[j],&A[j-1]);
			}
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
	printf("Thuat toan Bubble_Sort\n");
	Read(A,&n);
	printf("Danh sach chua sap xep: \n");
	Print(A,n);
	Bubble_Sort(A,n);
	printf("Danh sach sau khi sap xep: \n");
	Print(A,n);
	return 0;
}
