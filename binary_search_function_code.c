#include <stdio.h>
//বাইনারি সার্চের মূল উদ্দেশ্য হলো টার্গেটের ইনডেক্স খুঁজে বের করা

int binary_search(int arr[], int left, int right, int target)

 {
    if(left > right) return -1;
    //যদি left ইনডেক্স right ইনডেক্সের চেয়ে বড় হয়, এর মানে আমরা পুরো অ্যারেটা খুঁজে দেখেছি কিন্তু টার্গেট পাইনি। তাই আমরা -1 রিটার্ন করি।
    int mid = left + (right - left) / 2;
    /* left + (right - left)/2
= left + right/2 - left/2
= left/2 + right/2
= (left + right)/2 */

    if (arr[mid] == target)
    return mid;
else if (arr[mid] > target)
    return binary_search(arr, left, mid-1, target);
else
    return binary_search(arr, mid+1, right, target);
    /*ধরি, আমাদের অ্যারে: [2, 5, 8, 12, 16, 23, 38, 56, 72, 91] এবং টার্গেট = 23।

প্রথম ধাপ (left=0, right=9):
mid = 0 + (9-0)/2 = 4 → arr[4] = 16

arr[4] == 23? → 16 == 23? ❌ (false)

যেহেতু 16 < 23, আমরা ডান দিকে যাব (left = mid+1 = 5)।

দ্বিতীয় ধাপ (left=5, right=9):
mid = 5 + (9-5)/2 = 7 → arr[7] = 56

arr[7] == 23? → 56 == 23? ❌ (false)

যেহেতু 56 > 23, আমরা বাম দিকে যাব (right = mid-1 = 6)।

তৃতীয় ধাপ (left=5, right=6):
mid = 5 + (6-5)/2 = 5 → arr[5] = 23

arr[5] == 23? → 23 == 23? ✅ (true)

টার্গেট মিলে গেছে! তাই return 5; করবে (অর্থাৎ 23 আছে ইনডেক্স 5-এ)। */
}

int main() {

    int sorted[] = {2, 5, 8, 12, 16, 25, 38, 56, 72, 91};

    int target = 38;

    int index = binary_search(sorted, 0, 9, target);
   /* binary_search(sorted, 0, 9, target):

sorted: সর্টেড অ্যারে (যেমন: [2, 5, 8, 12, ..., 91])।

0: শুরু ইনডেক্স (অ্যারের প্রথম উপাদান)।

9: শেষ ইনডেক্স (অ্যারের শেষ উপাদান)।

target: যে সংখ্যাটি খুঁজছি (যেমন: 23)।

int index:

ফাংশন থেকে রিটার্ন করা ইনডেক্সটি index ভেরিয়েবলে স্টোর হয়।

যদি টার্গেট পাওয়া যায় (23), তাহলে index = 5 হবে।

না পেলে index = -1 হবে। */

if(index != -1)

        printf("%d Find it in the index %d\n", target, index);

    else

        printf("%d can not find it \n", target);

    return 0;
}
