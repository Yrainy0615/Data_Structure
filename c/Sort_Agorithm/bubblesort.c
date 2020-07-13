#include <stdio.h>
/*----冒泡排序-----
最差计算量O(n^2),最优计算量O(n)，平均计算量O(n^2)
*/
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

void bubble_sort(int A[], int n){
	for (int i = 0; i < n - 1; i++){
		for(int j = n - 1; j > i; j--){
			if (A[j-1] > A[j])
				swap(&A[j-1],&A[j]);			
		}
	}
}


int main(void) {
    int n = 10;
    int A[10] = {5, 9, 6, 4, 8, 1, 3, 10, 2, 7};

    print_array(A, n);
    bubble_sort(A,n);
    print_array(A, n);
}
