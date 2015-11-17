/*
	author : 15010925 ������
	date : 151025 22:20
*/
#include <stdio.h>
#include <stdlib.h>

int k; //k��.
int count1; // ���������� Ƚ��
int count2; // �������� Ƚ��

void swap(int* a, int* b, int isSwap){ // �� ���� �ٲ۴�. isSwap������ �ǹ����� �ٲ۰��� ī���õǴ� ��ȯȽ������ �Ǵ�.
    int tmp = *a;
    *a = *b;
    *b = tmp;
	count2+=isSwap;
}

void insert(int *arr, int start, int end){ //��������
	int i,j;
	int tmp;
	for(i=start+1;i<=end;i++){ // ù��°���� �̹� ������ �ι�°������ ������� ����
		tmp = arr[i];
		for(j=i-1;tmp<arr[j];j--){ //���Ե� �պκ� �迭�� �������� �˻��ϸ鼭 tmp<arr[j]�� ��ġ�� ����
			if(j<0) break; // ��ã���� Ż��
			arr[j+1] = arr[j]; //�迭�� ��ĭ�� ����
			count1++; // ī����
		} 
		arr[j+1] = tmp; //�迭�� ����� ����
	}

}

void quick(int *arr, int start, int end){ // ����Ʈ
	if(start==end || start>end) return; // start>end�� ��� ������ �ʿ䰡 ����.
	if(end-start<k) { //���ĵ��� k�� �迭�� ũ�⸦ ���� �������ķ� �ѱ��.
		insert(arr,start,end);
		return;
	}
	int pivot = arr[end]; // ���ذ��� �Ǵ� pivot��.
	int i = start-1; //�տ������� ���� i��
	int j; //�տ������� �˻��� j��

	for(j=start;j<=end-1;j++){
		if(arr[j]<=pivot) swap(&arr[++i],&arr[j], 1); // pivot�� ���ؼ� ����
	}

	swap(&arr[++i],&arr[end], 0); // pivot�� ��ġ�� �߰����� ����

	quick(arr, start, i-1); // pivot�� �պκ��� ���ȣ��
	quick(arr, i+1, end); // pivot�� �޺κ��� ���ȣ��
}


int main(){
	int n;
	int *arr;
	int i;
	scanf("%d",&n);
	scanf("%d",&k);
	arr = (int*)malloc(sizeof(int)*n); // �迭 �����Ҵ�

	for(i=0;i<n;i++){
		scanf("%d",&arr[i]); //�Է�
	}

	count1=0;
	count2=0;
	
	//nũ�⿡ ���� �����̳� ������ ȣ��
	if(n<=k){
		insert(arr,0,n-1);
	}	
	else{
		quick(arr,0,n-1);
	}

	for(i=0;i<n;i++){
		printf("%d",arr[i]);
		if(i!=n-1) printf(" "); //���� ������ �����ϰ� ���� ���
	}
	printf("\n%d\n%d",count1,count2); // ī���� ���
	
}