#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high, int ascending)
{
    int pivot = arr[low];
    int j = low;

    for (int i = low + 1; i <= high; i++)
    {
        if (  (ascending ==  1 ? arr[i] <= pivot : arr[i] >= pivot))
        {
            j++;
            swap(arr[i],arr[j]);
        }
    }
    pivot = j;
    swap(arr[low], arr[pivot]);

    return pivot;
}



void quickSort(vector<int>& arr, int low, int high, int ascending)
{
    if (low < high)
    {
        int pivotPos = partition(arr, low, high, ascending);
        quickSort(arr, low, pivotPos-1, ascending);
        quickSort(arr, pivotPos+1, high, ascending);

    }

}