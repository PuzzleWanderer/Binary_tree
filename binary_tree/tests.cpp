#include <cassert>
#include "libraries.hpp"
#include "functions.hpp"
#include "structures.hpp"

void Test_sorted(){
    std::vector<int> test_list = {9,8,7,6};
    std::vector<int> true_list = {6,7,8,9};
    assert(sorted(test_list) == true_list);

    test_list = {};
    true_list = {};
    assert(sorted(test_list) == true_list);

    test_list = {9,134,7,6};
    true_list = {6,7,9,134};
    assert(sorted(test_list) == true_list);

    test_list = {1};
    true_list = {1};
    assert(sorted(test_list) == true_list);

    test_list = {6,7,8,9};
    true_list = {6,7,8,9};
    assert(sorted(test_list) == true_list);

    std::cout << "Sorted OK" << std::endl;
}


void Test_finder(){
    std::vector<int> a = {1,2,3,4,5,6,7,8};
    Tree test_tree(a);
    
    //значения ссылок совпадают со значениями поиска
    for(int i = 1; i < 9; i++){
        assert(test_tree.id_ptr(i)->value == i);
    }
    
    //0 при попытке получить ссылку на несуществующий элемент
    assert(test_tree.id_ptr(9) == 0);


    std::cout << "Finder OK" << std::endl;
}


int main(){
    Test_sorted();
    Test_finder();
    return 0;
}