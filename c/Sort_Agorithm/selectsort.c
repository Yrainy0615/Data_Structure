#include <stdio.h>
/*----选择排序-----*/
//每次选最小的放到最左
//计算量O(n^2)
//不稳定

void swap(int *x, int *y) {
    int tmp;
    tmp = *x; *x = *y; *y = tmp;
    return;
}

void print_array(int A[], int n) {
    for (int i=0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void select_sort(int A[],int n){
	int min;
	for(int i = 0;i < n - 1;i++){
		min = i;
		for(int j = i + 1; j < n;j++){
			if(A[j] < A[min])
				min = j;		
		}
		swap(&A[i],&A[min]);
	}
}

int main(void) {
    int n = 10;
    int A[10] = {5, 9, 6, 4, 8, 1, 3, 10, 2, 7};

    print_array(A, n);
    select_sort(A,n);
    print_array(A, n);
}