#include <iostream>
#include <vector>
using namespace std;
// Merge function to merge two sorted subarrays
void merge(vector<int>& arr, int p, int q, int r) {
int n1 = q - p + 1;
int n2 = r - q;
// Create temporary arrays for the two halves
vector<int> left(n1), right(n2);
// Copy data to temporary arrays
for (int i = 0; i < n1; i++)
left[i] = arr[p + i];
for (int j = 0; j < n2; j++)
right[j] = arr[q + 1 + j];
// Merge the two halves back into arr
int i = 0, j = 0, k = p;
while (i < n1 && j < n2) {
if (left[i] <= right[j]) {
arr[k] = left[i];
i++;
} else {
arr[k] = right[j];
j++;
}
k++;
}
// Copy any remaining elements of left[]
while (i < n1) {
arr[k] = left[i];
i++;
k++;
}
// Copy any remaining elements of right[]
while (j < n2) {
arr[k] = right[j];
j++;
k++;
}
}
// Recursive merge sort function
void mergeSort(vector<int>& arr, int p, int r) {
if (p < r) {
int q = p + (r - p) / 2;
mergeSort(arr, p, q);
mergeSort(arr, q + 1, r);
merge(arr, p, q, r);
}
}
int main() {
int n;
cout << "Enter the number of elements: ";
cin >> n;
vector<int> arr(n);
cout << "Enter the elements: ";
for (int i = 0; i < n; i++)
cin >> arr[i];
cout << "Original array: ";
for (int i = 0; i < n; i++)
cout << arr[i] << " ";
cout << endl;
mergeSort(arr, 0, n - 1);
cout << "Sorted array: ";
for (int i = 0; i < n; i++)
cout << arr[i] << " ";
cout << endl;
return 0;
}
