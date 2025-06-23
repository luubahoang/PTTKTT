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
//PushDown
void PushDown(recordtype A[],int first,int last){
	int r = first;
	while (r <= (last-1)/2);
		if(last == 2*r+1) {
			if (A[r].key < A[last].key) swap(&A[r],&A[last]);
			r = last;
		}
		else 
		  if (A[r].key < A[2*r+1].key && A[2*r+1].key >= A[2*r+2].key){
		  	swap(&A[r],&A[2*r+1]);
		  	r = 2 * r+1;
		  }
		  else 
		  	if (A[r].key < A[2*r+2].key){
		  		swap(&A[r],&A[2*r+2]);
		  		r = 2*r+2;
			  }
			  else 
			  r = last;
}
//heap_Sort
void Heap_Sort(recordtype A[],int n){
	int i;
	for (i = (n-2)/2;i>=0;i--){
		PushDown(A,i,n-1);
	}
	for (i = n-1 ;i >= 2;i--){
		swap(&A[0],&A[i]);
		PushDown(A,0,i-1);
	}
	swap(&A[0],&A[1]);
	
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
	printf("Thuat toan Heap_Sort\n");
	Read(A,&n);
	printf("Danh sach chua sap xep: \n");
	Print(A,n);
	Heap_Sort(A,n);
	printf("Danh sach sau khi sap xep: \n");
	Print(A,n);
	return 0;
}
