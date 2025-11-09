#include<iostream>

using namespace std;


// Quick Sort function to sort an array
int sort(int arr[], int n) {
    if (n <= 1) {
        return 0; // Array is already sorted
    }

    int pivot = arr[n / 2];
    int left[n], right[n];
    int leftCount = 0, rightCount = 0;

    for (int i = 0; i < n; i++) {
        if (i == n / 2) continue; // Skip the pivot element
        if (arr[i] < pivot) {
            left[leftCount++] = arr[i];
        } else {
            right[rightCount++] = arr[i];
        }
    }

    sort(left, leftCount);
    sort(right, rightCount);

    // Combine results
    for (int i = 0; i < leftCount; i++) {
        arr[i] = left[i];
    }
    arr[leftCount] = pivot;
    for (int i = 0; i < rightCount; i++) {
        arr[leftCount + 1 + i] = right[i];
    }

    return 0;
}

// Bubble Sort function to sort an array
int bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return 0;
}

// Selection Sort function to sort an array
int selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap arr[i] and arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    return 0;
}

int main() {
    int arr[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}