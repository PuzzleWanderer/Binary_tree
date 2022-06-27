//Возвращает отсортированный массив
std::vector<int> sorted(std::vector<int> list){
    int s = list.size();
    for(int i = 0; i < s; i++){
        int minimum = list[i];
        int num = i;
        for(int j = i; j < s; j++){
            if(list[j] < minimum){
                num = j;
                minimum = list[j];
            }
        }
        int change = list[i];
        list[i] = list[num];
        list[num] = change;
    }
    return list;
}


//Выводит элементы динамического массива
void print_vector(std::vector<int> list){
    std::cout << "Elements: " << std::endl;
    int s = list.size();
    for(int i = 0; i < s; i++){
        std::cout << i << ": " << list[i] << std::endl;
    }
}