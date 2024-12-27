#include <iostream>
#include <vector>


using namespace std;


//필수 과제1 
int sum(int arr[], int n)
{
    int total = 0;


    for (int i = 0; i < n; i++)
        total += arr[i];

    return total;
}

float average(int sum, int n)
{
    float average = sum / (float)n;

    return average;

}

// 도전과제 1
int partition(vector<int>& arr, int low, int high, int ascending)
{
    int pivot = arr[low];
    int j = low;

    for (int i = low + 1; i <= high; i++)
    {
        if ((ascending == 1 ? arr[i] <= pivot : arr[i] >= pivot))
        {
            j++;
            swap(arr[i], arr[j]);
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
        quickSort(arr, low, pivotPos - 1, ascending);
        quickSort(arr, pivotPos + 1, high, ascending);

    }

}


void merge(vector<int>& arr, int left, int mid, int right, int ascending)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1), rightArr(n2);
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (ascending == 1 ? leftArr[i] <= rightArr[j] : leftArr[i] >= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = leftArr[i++];
    }
    while (j < n2)
    {
        arr[k++] = rightArr[j++];
    }
}



void mergeSort(vector<int>& arr, int left, int right, int ascending)
{
    if (left < right)
    {
        int mid = left + (right-left)/2;
        mergeSort(arr, left, mid, ascending);
        mergeSort(arr, mid + 1, right, ascending);
        merge(arr, left, mid, right, ascending);
    }

}





int main()
{

    int arr[100];
    cout << "숫자 입력하세요 : ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int total = sum(arr, n);
    float avg = average(total, n);
    cout << "합 : " << total << ", 평균 : " << avg << endl;

   

    vector<int> sortArr(5);
    cout << "숫자 5개를 입력하세요 : ";
    for (int i = 0; i < 5; i++)
        cin >> sortArr[i];

    mergeSort(sortArr, 0, 4, 1);
    for (int i = 0; i < 5; i++)
        cout << sortArr[i] << " ";
    cout << endl;

    quickSort(sortArr, 0, 4, 2);
    for (int i = 0; i < 5; i++)
        cout << sortArr[i] << " ";
    cout << endl;
        

}