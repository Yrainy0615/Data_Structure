#include <stdio.h>
/*------快速排序--------*/
//在数组中随机选一个数（默认数组首个元素），数组中小于等于此数的放在左边，大于此数的放在右边，再对数组两边递归调用快速排序，重复这个过程。
//不稳定排序
//最差计算量O(n^2),最优计算量O(nlogn),平均计算量O(nlogn)
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

void quick_sort(int A[], int left, int right) {
    if (left < right) {  //递归条件
        int i = left;
        int j = right;
        int pivot = A[(i+j)/2];  //pivot为基准值
        while(1) {
            while (A[i] < pivot) i++;  // 在pivot左边找大于基准的数
            while (A[j] > pivot) j--;    //在pivot右边找大小于基准的数
            if (i < j) {
                swap(&A[i], &A[j]); // 交换
            } else {
                break;
            }
            i++; j--; //交换后继续找下一组要交换的
        }

        quick_sort(A, left, i-1);   //对左边递归调用
        quick_sort(A, j+1, right);  //对右边递归调用
    }
}

int main(void) {
    int n = 10;
    int A[10] = {5, 9, 6, 4, 8, 1, 3, 10, 2, 7};

    print_array(A, n);
    quick_sort(A,0 ,n);
    print_array(A, n);
}