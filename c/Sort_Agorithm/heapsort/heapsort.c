#include <stdio.h>

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

//向下调整
void shift_down(int A[], int x, int n) {
    // A:待排数组
    // x:当前关注的节点
    // n:A的size
    while (2*x+1 <= n-1) {   // 当前节点还有子时
        int ynode;  // y的下标
        int yvalue; // y的值
        if (2*x+1 == n-1) {  //只有左子
            ynode = n-1;
            yvalue = A[n-1];
        } else {             //有左右子，与值大的那个作比较
            if (A[2*x+1] <= A[2*x+2]) {
                ynode = 2*x+2;
                yvalue = A[2*x+2];
            } else {
                ynode = 2*x+1;
                yvalue = A[2*x+1];
            }
        }
        if (A[x] < yvalue) {
            swap(&A[x], &A[ynode]);
            x = ynode;//保存父节点下标
        } else {
            return;
        }
    }
}

void build_heap(int A[], int n) {
    for (int x = (n/2)-1; x >= 0; x--) {
        shift_down(A, x, n);
    }
}

void heap_sort(int A[], int n) {
    build_heap(A, n);
    for (int m = n-1; m > 0; m--) {
        swap(&A[0], &A[m]);
        shift_down(A, 0, m);
    }
}


int main(void) {
    int n = 10;
    int A[10] = {5, 9, 6, 4, 8, 1, 3, 10, 2, 7};

    print_array(A, n);
    heap_sort(A, n);
    print_array(A, n);
}