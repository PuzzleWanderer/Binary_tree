#include "libraries.hpp"
#include "functions.hpp"
#include "structures.hpp"

// все id должны быть различны и иметь одинаковую длину
// 0 не может быть id, он означает конец дерева

int main(){
    std::vector<int> a = {9,6,8,3,5,4};
    std::vector<int> b = sorted(a);
    print_vector(a);
    print_vector(b);
    Tree boba(b);
    boba.print();
    Leaf* ptr = boba.id_ptr(4);
    std::cout << ptr << std::endl;
    std::cout << ptr->value << std::endl;

    a = {5,2,7};
    a = sorted(a);
    Tree biba(a);
    biba.print();
    ptr = biba.id_ptr(1);
    std::cout << ptr << std::endl;
}