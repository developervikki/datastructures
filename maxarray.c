#include <stdio.h>

int main() {
    int i,arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;

    for(i = 0; i < n; i++) {
        sum += arr[i]; 
    }

    printf("The sum of all elements in the array is %d\n", sum);

    return 0;
}
