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
//Select_Sort
void Select_Sort(recordtype A[],int n){
	int i,j,lowindex;
	keytype lowkey;
	for (i= 0 ; i<= n-2;i++){
		lowkey = A[i].key;
		lowindex = i;
		for (j = i +1 ; j<= n-1;j++){
			if (A[j].key < lowkey){
				lowkey = A[j].key;
				lowindex = j;
			}
		}
		swap(&A[i],&A[lowindex]);
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
	printf("Thuat toan Select_Sort\n");
	Read(A,&n);
	printf("Danh sach chua sap xep: \n");
	Print(A,n);
	Select_Sort(A,n);
	printf("Danh sach sau khi sap xep: \n");
	Print(A,n);
	return 0;
}
