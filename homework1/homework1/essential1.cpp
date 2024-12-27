#include <iostream>

using namespace std;

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

int main()
{

    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int total = sum(arr, n);
    float avg = average(total, n);
    cout << "Че : " << total << ", ЦђБе : " << avg << endl;

}