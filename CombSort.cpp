#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
int getGap(int n)
{
    n = (n*10)/13;
    if (n < 1)
        return 1;
    return n;
}
void Combsort(vector<int>& a, int n)
{
    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped == true)
    {
        gap = getGap(gap);
        swapped = false;
        for (int i=0; i<n-gap; i++)
        {
            if (a[i] > a[i+gap])
            {
                swap(a[i], a[i+gap]);
                swapped = true;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        a[i]=rand()%1000000000;
    }
    auto start=high_resolution_clock::now();
    Combsort(a,n);
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(end-start);
    cout<<duration.count();
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
}