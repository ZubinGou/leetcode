#include <iostream>
using namespace std;

const int N = 110, MAX_N = 1e8;

int n;
int a[N];

int h[N], idx; //heap_sort用
int tmp[N];    //merge_sort用
int bkt[MAX_N];  //counting_sort用

void bubble_sort()
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])  // 大的往后沉
                swap(a[j], a[j + 1]);
        }
}

void quick_sort(int l, int r)
{
    if (l >= r)
        return;
    int pivot_idx = (r - l) / 2 + l;
    // int pivot_idx = l;
    int pivot = a[pivot_idx];
    int i = l, j = r;
    while (i < j)
    {
        while (i < j && a[j] >= pivot)  // 必须先移右边的指针
            j--;
        while (i < j && a[i] <= pivot)
            i++;
        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[i], a[pivot_idx]);

    quick_sort(l, i - 1);
    quick_sort(i + 1, r);
}

void selection_sort()
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min_pos])
                min_pos = j;
        swap(a[i], a[min_pos]);  // 每次选最小的放到前面
    }
}

void down(int u)
{
    int t = u;
    if (u * 2 <= idx && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= idx && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (t != u)
    {
        swap(h[t], h[u]);
        down(t);
    }
}

void heap_sort()
{
    for (int i = 1; i <= n; i++)
        h[i] = a[i - 1];
    idx = n;
    for (int i = idx / 2; i > 0; i--)
        down(i);
    for (int i = 0; i < n; i++)
    {
        a[i] = h[1];
        h[1] = h[idx--];
        down(1);
    }
}

void insertion_sort()
{
    for (int i = 1; i < n; i++)
    {
        int cur_idx = a[i];
        int j;
        for (j = i - 1; j >= 0 && a[j] > cur_idx; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = cur_idx;
    }
}

void binary_insertion_sort()
{
    for (int i = 1; i < n; i++)
    {
        int cur_idx = a[i];
        int l = 0, r = i - 1;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (a[mid] <= cur_idx)
                l = mid;
            else
                r = mid - 1;
        }
        if (a[l] > cur_idx)
            l = -1;
        int j;
        for (j = i - 1; j > l; j--)
            a[j + 1] = a[j];
        a[j + 1] = cur_idx;
    }
}

void shell_sort()
{
    for (int gap = n / 2; gap >= 1; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int cur_idx = a[i];
            int j;
            for (j = i - gap; j >= 0 && a[j] > cur_idx; j -= gap)
            {
                a[j + gap] = a[j];
            }
            a[j + gap] = cur_idx;
        }
    }
}

void merge_sort(int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];
    for (int i = l, j = 0; i <= r; j++, i++)
        a[i] = tmp[j];
}

void counting_sort()
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        bkt[a[i]]++;
        if (a[i] > max)
            max = a[i];
    }
    int j = 0;
    for (int i = 0; i < max + 1; i++)
    {
        while (bkt[i])
        {
            a[j++] = i;
            bkt[i]--;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // bubble_sort();
    quick_sort(0, n - 1);
    // selection_sort();
    // heap_sort();
    // insertion_sort();
    // binary_insertion_sort();
    // shell_sort();
    // merge_sort(0, n - 1);
    // counting_sort();
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}