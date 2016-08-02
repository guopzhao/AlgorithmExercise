#include <iostream>

using namespace std;

/*binsearch : find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    int counter = 0;
    while (low <= high) {
        printf("%d\n", counter++);
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        }
        else if (x > v[mid]) {
            low = mid + 1;
        }
        else { /*found match*/
            int low_second = low;
            int high_second = mid;
            int mid_second;
            if (mid - 1 >= 0) {
                while (low_second < high_second) {
                    printf("%d\n", counter++);
                    mid_second = (low_second + high_second) / 2;
                    if (v[mid_second] < x) {
                        low_second = mid_second + 1;
                    }
                    else {
                        high_second = mid_second;
                    }
                }
            }
            return v[mid_second] == x ? mid_second : mid_second + 1;
        }
    }

    return -1;
}

int binsearch2(int x, int v[], int n) {
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (v[mid] >= x) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    if(low < n && v[low] == x)
        return low;
    else
        return -1;
}

int bSearchFirstIndex(int *arr, int low, int high, int key) {
    int mid, left = low, right = high;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (arr[mid] >= key) right = mid - 1;    //如果要求是返回大于key的第一个数的位置则将arr[mid] >= key修改为arr[mid] > key
        else left = mid + 1;
    }
    return left;
}

int main() {
    int array[] = {1,2,4,6,7,8,9,9,9};
    int location;
    int number = 7;
    int len = sizeof(array) / sizeof(array[0]);
    location = binsearch2(number, array, len);
    printf("\n\n%d\n", location);

    int location2 = bSearchFirstIndex(array, 0, len, number);
    printf("\n\n%d\n", location2);
    return 0;
}