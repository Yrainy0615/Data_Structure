#include <stdio.h>
/*----插入排序-----
当前数往前查找待插位置，查找过程中数据整体后移一位,最后插入
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

void insertion_sort(int A[], int n){
	int insert;
	for(int i = 1; i < n; i++){
		insert = A[i];
		int j = i - 1;
		while(j >= 0 && insert < A[j]){
			A[j+1] = A[j];
			j = j - 1;
		}
		A[j+1] = insert;
	}

}

int main(void) {
    int n = 10;
    int A[10] = {5, 9, 6, 4, 8, 1, 3, 10, 2, 7};

    print_array(A, n);
    insertion_sort(A,n);
    print_array(A, n);
}