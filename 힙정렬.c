#include <stdio.h>

// 힙의 구조를 유지하는 함수
void heapify(int arr[], int n, int i) {
    int largest = i; // 루트를 가장 큰 값으로 설정
    int left = 2 * i + 1; // 왼쪽 자식 노드
    int right = 2 * i + 2; // 오른쪽 자식 노드

    // 왼쪽 자식 노드가 루트보다 큰 경우
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 오른쪽 자식 노드가 현재 가장 큰 값보다 큰 경우
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 가장 큰 값이 루트가 아닌 경우 교환
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // 교환된 자식 노드를 다시 힙화
        heapify(arr, n, largest);
    }
}

// 힙정렬 함수
void heapSort(int arr[], int n) {
    // 배열을 힙으로 변환
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 힙에서 요소를 하나씩 추출하여 정렬
    for (int i = n - 1; i >= 0; i--) {
        // 루트(가장 큰 값)와 마지막 요소를 교환
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 교환된 힙의 루트 노드를 힙화
        heapify(arr, i, 0);
    }
}

// 배열을 출력하는 함수
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("정렬 전 배열: \n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("힙정렬 후 배열: \n");
    printArray(arr, n);

    return 0;
}
