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
//Quick_Sort
//Find_Sort
int FindPivot(recordtype A[], int i,int j){
	keytype firstkey;
	int k ;
	k = i+1;
	firstkey = A[i].key;
	while((k<=j) &&(A[k].key ==firstkey)) k++;
	if (k>j) return -1;
	if (A[k].key < firstkey) return k;
	return i;
}
//Partition
int Partition(recordtype A[],int i,int j, keytype pivot){
	int L,R;
	L = i;
	R = j;
	while (L <= R){
		while (A[L].key <= pivot) L++;
		while (A[R].key > pivot) R--;
		if (L < R) swap(&A[L],&A[R]);
	}
	return L;
}
//Quick_Sort
void Quick_Sort(recordtype A[],int i, int j){
	keytype pivot;
	int pivotindex,k;
	pivotindex = FindPivot(A,i,j);
	if (pivotindex != -1){
		pivot = A[pivotindex].key;
		k = Partition(A,i,j,pivot);
		Quick_Sort(A,i,k-1);
		Quick_Sort(A,k,j);
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
	printf("Thuat toan Quick_Sort bien the\n");
	Read(A,&n);
	printf("Danh sach chua sap xep: \n");
	Print(A,n);
	Quick_Sort(A,0,n-1);
	printf("Danh sach sau khi sap xep: \n");
	Print(A,n);
	return 0;
}
