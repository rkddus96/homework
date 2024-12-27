#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right, int ascending)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1), rightArr(n2);
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n1; i++)
        rightArr[i] = arr[mid+1 + i];

    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid || j <= right)
    {
        if (ascending == 1 ?leftArr[i] <= rightArr[j] : leftArr[i] >= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
        }
    }

    while (i <= mid)
    {
        arr[k++] = leftArr[i++];
    }
    while (j <= right)
    {
        arr[k++] = rightArr[j++];
    }
}



void mergeSort(vector<int>& arr, int left, int right, int ascending)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, ascending);
        mergeSort(arr, mid + 1, right, ascending);
        merge(arr, left, mid, right, ascending);
    }

}

