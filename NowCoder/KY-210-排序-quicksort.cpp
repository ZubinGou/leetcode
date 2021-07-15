#include <iostream>
#include <ctime> // for `time`

using namespace std;

const int MAX_N = 1e7;

int n;
int a[MAX_N];

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int partition(int left, int right) {
    // 快排简单写法：双指针前移法（需要指定 pivot 为最后一个元素）
    int pivot = a[right];
    int i = left;
    int j = right;
    for (int j = left; j < right; j++) {
        if (a[j] < pivot)  // 将小的元素依次移动到开头
            swap(a[i++], a[j]);
    }
    swap(a[i], a[right]);
    return i;
}

int random_partition(int left, int right) {
    srand(time(NULL));
    int pivot = left + rand() % (right - left);
    swap(a[pivot], a[right]);
    return partition(left, right);
}

int mid_partition(int left, int right) {
     int pivot = (right - left) / 2 + left;
    swap(a[pivot], a[right]);
    return partition(left, right);
}

void quick_sort(int left, int right) {
    if (left < right) {
        // int pi = partition(left, right);
        // int pi = mid_partition(left, right);
        int pi = random_partition(left, right);
        quick_sort(left, pi - 1);
        quick_sort(pi + 1, right);
    }
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quick_sort(0, n-1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}