#include <iostream>
using namespace std;
// Function to swap two elements
void swap(int& a, int& b) {
int temp = a;
a = b;
b = temp;
}
// Partition function to rearrange the elements around the pivot
int Partition(int a[], int low, int high) {
int pivot = a[low]; // The pivot element is chosen to be the first element
int i = low+1; // i starts at the low index
int j = high; // j starts at high + 1, as we will decrement it before using
// Loop until the indices i and j cross
while (true) {
// Increment i until we find an element greater than the pivot
while (a[i] <= pivot && i <= high)i++;
// Decrement j until we find an element less than the pivot
while (a[j] > pivot)j--;
// If indices cross, exit the loop
if (i >= j) {
break;
}
// Swap elements at i and j
swap(a[i], a[j]);
}
// Finally, place the pivot in the correct position
swap(a[low], a[j]);
return j; // Return the index of the pivot
}
// QuickSort function
void QuickSort(int a[], int low, int high) {
if (low < high) {
// Partition the array and get the pivot index
int j = Partition(a, low, high);
// Recursively sort the left and right subarrays
QuickSort(a, low, j - 1);
QuickSort(a, j + 1, high);
}
}
int main() {
int n;
// Take input for the size of the array
cout << "Enter the number of elements: ";
cin >> n;
int a[n];
// Take input for the elements of the array
cout << "Enter the elements of the array: ";
for (int i = 0; i < n; i++) {
cin >> a[i];
}
// Call QuickSort with initial low and high indices
QuickSort(a, 0, n - 1);
// Output the sorted array
cout << "Sorted array: ";
for (int i = 0; i < n; i++) {
cout << a[i] << " ";
}
cout << endl;
return 0;
}
