// Copyright 2022 <Trudieis>
#include <stdio.h>
#define NMAX 10

int input(int *a);
void swap(int *a, int *b);
void printArray(int *a);
void merge_sort(int *a);
void merge_sort_recursion(int *a, int l, int r);
void merge_sorted_arrays(int *a, int l, int m, int r);
void heapify(int *arr, int n, int i);
void heapSort(int *arr, int n);

int main() {
    int data[NMAX];
    if (input(data) == 0) {
        merge_sort(data);
        printArray(data);
        heapSort(data, NMAX);
        printArray(data);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a) {
    int i = 0;
    for (int *p = a; p - a < NMAX; p++) {
        if (scanf("%d", p) != 1) {
            i++;
            break;
        }
    }
    if (getchar() != '\n') {
        i++;
    }
    return i;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printArray(int *a) {
  for (int i = 0; i < NMAX; i++) {
    (i == NMAX - 1) ? printf("%d\n", a[i]) : printf("%d ", a[i]);
  }
}

void merge_sort(int *a) {
  merge_sort_recursion(a, 0, NMAX - 1);
}

void merge_sort_recursion(int *a, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    merge_sort_recursion(a, l, m);
    merge_sort_recursion(a, m + 1, r);
    merge_sorted_arrays(a, l, m, r);
  }
}

void merge_sorted_arrays(int *a, int l, int m, int r) {
  int leftLength = m - l + 1;
  int rightLength = r - m;
  int tempLeft[leftLength];
  int tempRight[rightLength];
  int i, j, k;
  for (int i = 0; i < leftLength; i++) {
    tempLeft[i] = a[l + i];
  }
  for (int i = 0; i < rightLength; i++) {
    tempRight[i] = a[m + 1 + i];
  }
  for (i = 0, j = 0, k = l; k <= r; k++) {
    if ((i < leftLength) &&
        (j >= rightLength || tempLeft[i] <= tempRight[j])) {
      a[k] = tempLeft[i];
      i++;
    } else {
      a[k] = tempRight[j];
      j++;
    }
  }
}

void heapify(int *arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
      largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
      largest = r;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
      heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
    }
}
