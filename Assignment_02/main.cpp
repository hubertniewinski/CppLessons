#include <iostream>
#include <string> // for tests
#include <ctime> // time
#include <utility> // std::swap may be useful

template <typename T, typename FUN>
size_t part(T* arr, size_t size, FUN f) {
    int lastValid = 0;
    for(int i = 0;i<size;i++){
        if(f(arr[i]) && lastValid+1 < size){
            std::swap(arr[i], arr[lastValid++]);
        }
    }

    return lastValid;
}

template <typename T>
void printTab(const T* t, size_t size) {
    std::cout<<"{ ";
    for(int i=0;i<size;i++)
        std::cout<<t[i]<<" ";
    std::cout<<" }"<<std::endl;
}

bool isEven(int e) { return e%2 == 0; }

int main() {
    size_t ind = 0;

    int a1[] = {1, 2, 3, 4, 5, 6};

    ind = part(a1, 6, isEven);
    std::cout << "ind = " << ind << " ";
    printTab(a1, 6);
    int a2[] = {1, 2, 3, 4, 5, 6};

    ind = part(a2, std::size(a2), [](int e){return !isEven(e);});

    std::cout << "ind = " << ind << " ";
    printTab(a2, std::size(a2));

    std::string a3[] = {"Ala", "Ula", "Ela", "Ola", "Maja"};
    std::string mn = "Bea";
    std::string mx = "Sue";

    ind = part(a3, std::size(a3), [mn,mx](std::string compare){return mn <= compare && mx >= compare;} );

    std::cout << "ind = " << ind << " ";
    printTab(a3, std::size(a3));

    constexpr size_t DIM = 500000;
    int *a4 = new int[DIM];

    srand(unsigned(time(0)));

    for (size_t i = 0; i < DIM; ++i)
        a4[i] = rand() % 21 + 1;

    ind = part(a4, DIM, [](int i){return i % 7 == 0;} );

    std::cout << "ind = " << ind << std::endl;

    delete[] a4;
}