
#include <iostream>
using namespace std;
void changeArray(int (&arr)[5]) {
    for (int i = 0; i < 5; i++) {
        arr[i] *= 2;
    }
}
int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    changeArray(numbers);
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    return 0;
}