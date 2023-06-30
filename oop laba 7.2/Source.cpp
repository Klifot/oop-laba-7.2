#include <iostream>

template<typename T>
void shellSort(T arr[], int size) {
    // Визначаємо розмір кроку
    int gap = size / 2;

    while (gap > 0) {
        // Застосовуємо алгоритм сортування вставками з кроком gap
        for (int i = gap; i < size; i++) {
            T temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }

        // Зменшуємо розмір кроку
        gap /= 2;
    }
}

int main() {
    int intArr[] = { 5, 2, 7, 3, 1 };
    char charArr[] = "water";

    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    int charSize = sizeof(charArr) / sizeof(charArr[0]) - 1;  // -1 для врахування символу '\0'

    shellSort(intArr, intSize);

    std::cout << "Sorted integer array: ";
    for (int i = 0; i < intSize; i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    shellSort(charArr, charSize);

    std::cout << "Sorted char array: " << charArr << std::endl;

    return 0;
}