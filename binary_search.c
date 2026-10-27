#include <stdio.h>

int binarysearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        else if (arr[mid] < target){
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;

}

int main(void) {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = binarysearch(arr, size, target);

    if (result == -1) printf("Target not found.\n");
    else printf("Target found at index %d\n", result);

    return 0;
}