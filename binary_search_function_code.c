#include <stdio.h>
//বাইনারি সার্চের মূল উদ্দেশ্য হলো টার্গেটের ইনডেক্স খুঁজে বের করা

int binary_search(int arr[], int left, int right, int target)

 {
    if(left > right) return -1;

    int mid = left + (right - left) / 2;


    if (arr[mid] == target)
    return mid;
else if (arr[mid] > target)
    return binary_search(arr, left, mid-1, target);
else
    return binary_search(arr, mid+1, right, target);
}

int main() {

    int arr[] = {2, 5, 8, 12, 16, 25, 38, 56, 72, 91};

    int target = 38;

    int index = binary_search(arr, 0, 9, target);


if(index != -1)

        printf("%d Find it in the index %d\n", target, index);

    else

        printf("%d can not find it \n", target);

    return 0;
}
