#include <iostream>
#include <ctime> // for `time`
#include <stack>

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
    if (left == right) return;
    // 用栈依次存储左右指针
    stack<int> st;
    st.push(left);  // 先左后右
    st.push(right);

    while (!st.empty()) {
        int r = st.top();
        st.pop();
        int l = st.top();
        st.pop();
        if (l < r) {
            int pi = random_partition(l, r);
            if (pi > l) {
                st.push(l);
                st.push(pi - 1);
            }
            if (pi < r) {
                st.push(pi + 1);
                st.push(r);
            }
        }
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