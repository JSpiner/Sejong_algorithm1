/*
	author : 15010925 정성민
	date : 151025 22:20
*/
#include <stdio.h>
#include <stdlib.h>

int k; //k값.
int count1; // 삽입정렬의 횟수
int count2; // 퀵정렬의 횟수

void swap(int* a, int* b, int isSwap){ // 두 값을 바꾼다. isSwap변수로 피벗값을 바꾼건지 카운팅되는 교환횟수인지 판단.
    int tmp = *a;
    *a = *b;
    *b = tmp;
	count2+=isSwap;
}

void insert(int *arr, int start, int end){ //삽입정렬
	int i,j;
	int tmp;
	for(i=start+1;i<=end;i++){ // 첫번째값은 이미 있으니 두번째값부터 순서대로 삽입
		tmp = arr[i];
		for(j=i-1;tmp<arr[j];j--){ //삽입된 앞부분 배열을 역순으로 검색하면서 tmp<arr[j]인 위치에 삽입
			if(j<0) break; // 못찾을시 탈출
			arr[j+1] = arr[j]; //배열을 한칸씩 땡김
			count1++; // 카운팅
		} 
		arr[j+1] = tmp; //배열을 땡긴뒤 삽입
	}

}

void quick(int *arr, int start, int end){ // 퀵소트
	if(start==end || start>end) return; // start>end일 경우 정렬할 필요가 없다.
	if(end-start<k) { //정렬도중 k와 배열의 크기를 비교해 삽입정렬로 넘긴다.
		insert(arr,start,end);
		return;
	}
	int pivot = arr[end]; // 기준값이 되는 pivot값.
	int i = start-1; //앞에서부터 넣을 i값
	int j; //앞에서부터 검색할 j값

	for(j=start;j<=end-1;j++){
		if(arr[j]<=pivot) swap(&arr[++i],&arr[j], 1); // pivot과 비교해서 변경
	}

	swap(&arr[++i],&arr[end], 0); // pivot의 위치를 중간으로 설정

	quick(arr, start, i-1); // pivot의 앞부분을 재귀호출
	quick(arr, i+1, end); // pivot의 뒷부분을 재귀호출
}


int main(){
	int n;
	int *arr;
	int i;
	scanf("%d",&n);
	scanf("%d",&k);
	arr = (int*)malloc(sizeof(int)*n); // 배열 동적할당

	for(i=0;i<n;i++){
		scanf("%d",&arr[i]); //입력
	}

	count1=0;
	count2=0;
	
	//n크기에 따라 선택이나 퀵정렬 호출
	if(n<=k){
		insert(arr,0,n-1);
	}	
	else{
		quick(arr,0,n-1);
	}

	for(i=0;i<n;i++){
		printf("%d",arr[i]);
		if(i!=n-1) printf(" "); //제일 마지막 제외하고 공백 출력
	}
	printf("\n%d\n%d",count1,count2); // 카운팅 출력
	
}