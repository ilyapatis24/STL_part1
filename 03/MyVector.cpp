#include "MyVector.h"

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");

    MyVector<int> vect;
    vect.push_back(10);
    vect.push_back(20);
    printVector(vect);

    try
    {
        std::cout << "v1[0] = " << vect.at(0) << std::endl;
        std::cout << "vector_size = " << vect.size() << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}