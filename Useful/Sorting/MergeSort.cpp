/*
Как устроен MergeSort?

Берём массив, разделяем его на половины до тех пор, пока не получим массивы из одного элемента.

Например:
   [3, 4, 5, 7, 2, 1, 4, 0]
               |
   [3, 4, 5, 7] [2, 1, 4, 0]
               |
 [3, 4]  [5, 7] [2, 1] [4, 0]
               |
[3] [4] [5] [7] [2] [1] [4] [0]

Массив из одного элемента не может быть не отсортированным (капитан Очевидность).
Далее, объединяем отсортированные массивы. That's all!

Как работает слияние двух отсортированных массивов?

Возьмём 3 массива: a[i], b[j], result[i + j]. Массивы a и b - отсортированные.
Идём по массивам, сравнивая их элементы, и вносим их в result.
Result - новый массив, получившийся из слияния a и b.

Пример:
        int а = {3, 4, 5, 7, 9};
        int b = {2, 2, 8};
        int result[8];
        a[0] > b[0] -> result[0] = b[0]
        a[0] > b[1] -> result[1] = b[1]
        a[0] < b[2] -> result[2] = a[1]
        И так далее...
*/

#include <iostream>

void Copy(int* from, int* from_end, int* to) {
    while (from != from_end) {
        *to++ = *from++;
    }
}

void Merge(int* lhs, int* lhs_end, int* rhs, int* rhs_end, int* result) {
    while (lhs < lhs_end && rhs < rhs_end) {
        if (*lhs <= *rhs) {
            *result++ = *lhs++;
        } else {
            *result++ = *rhs++;
        }
    }

    while (lhs < lhs_end) {
        *result++ = *lhs++;
    }
    while (rhs < rhs_end) {
        *result++ = *rhs++;
    }
}

void MergeSort(int* array, int n) {
    if (n == 1) {
        return;
    }
    int mid = n / 2;
    int* temp = new int[n];

    MergeSort(array, mid);
    MergeSort(array + mid, n - mid);
    Merge(array, array + mid, array + mid, array + n, temp);
    Copy(temp, temp + n, array);

    delete[] temp;
}

int main() {
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    MergeSort(arr, n);
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }
    return 0;
}
