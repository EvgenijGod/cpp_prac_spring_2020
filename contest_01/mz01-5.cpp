#include <iostream>

int main()
{
    int count;
    std::cin >> count;
    Holder *arr = new Holder[count]();
    for (int i = 0; i < count / 2; i++) {
        arr[i].swap(arr[count - 1 - i]);
    }
    delete[]arr;
    // далее стандартную библиотеку использовать нельзя
}