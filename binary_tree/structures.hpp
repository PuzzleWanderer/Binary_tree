struct Leaf{
    std::unique_ptr<Leaf> left;
    std::unique_ptr<Leaf> right;
    int value;

    Leaf(int avalue, std::unique_ptr<Leaf> &&aleft = nullptr, std::unique_ptr<Leaf> &&aright = nullptr)
        : value(avalue), left(std::move(aleft)), right(std::move(aright)) {}
};


struct Tree{
    std::unique_ptr<Leaf> head;


    //Создает дерево из 1 элемента
    Tree(int value){
        head = std::make_unique<Leaf>(Leaf(value));
    }


    //Создает лучший вариант дерева из отсортированного списка
    Tree(std::vector<int> sorted_list){
        int s = sorted_list.size();
        int c = s/2;
        head = std::make_unique<Leaf>(Leaf(sorted_list[c]));

        if(s >= 2){
            std::vector<int> left;
            for(int i = 0; i < c; i++){
                left.push_back(sorted_list[i]);
            }
            Tree left_tree(left);
            head->left = std::move(left_tree.head);
        }

        if(s > 2){
            std::vector<int> right;
            for(int i = c+1; i < s; i++){
                right.push_back(sorted_list[i]);
            }
            Tree right_tree(right);
            head->right = std::move(right_tree.head);
        }
    }


    //Выводит дерево в консоль
    void print(){
        std::vector<std::vector<int>> lvls;
        std::vector<Leaf*> floor;
        floor.push_back(this->head.get());
        std::vector<int> lvl = {floor[0]->value};
        lvls.push_back(lvl);
        
        while(floor.size() != 0){
            std::vector<Leaf*> new_floor;
            lvl = {};
            for(int i = 0; i < floor.size(); i++){
                if(floor[i]->left.get() != nullptr){
                    lvl.push_back(floor[i]->left->value);
                    new_floor.push_back(floor[i]->left.get());
                }
                else{
                    lvl.push_back(0);
                }

                if(floor[i]->right.get() != nullptr){
                    lvl.push_back(floor[i]->right->value);
                    new_floor.push_back(floor[i]->right.get());
                }
                else{
                    lvl.push_back(0);
                }
            }
            lvls.push_back(lvl);
            floor = new_floor;
            new_floor = {};
        }

        int n = lvls.size();
        bool er = 1;
        for(int i = 0; i < lvls[n-1].size(); i++){
            if(lvls[n-1][i] != 0){
                er = 0;
                break;
            }
        }

        int first = lvls[0][0];
        int len = 0;

        while(first != 0){
            len++;
            first/=10;
        }

        int len_spaces = 1;
        int max_y = lvls[n-1-er].size();
        for(int i = 0; i < max_y; i++){
            if(len_spaces % (i+1) != 0){
                len_spaces*=(i+1);
            }
        }
        int num_leafs = lvls[n-1-er].size();
        int num_ch = num_leafs*(len+len_spaces);

        for(int i = 0; i < n-er; i++){
            int y = lvls[i].size();
            std::string spaces = "";
            spaces.insert(0,num_ch/(y+1),' ');
            for(int j = 0; j < y; j++){
                std::cout << spaces << lvls[i][j];
            }
            std::cout << std::endl;
        }
    }

    //Возвращает ссылку на элемент с нужным id или 0, если такого элемента нет
    Leaf* id_ptr(int id){
        Leaf* ptr = this->head.get();
        int value = ptr->value;

        while(value != id){
            if(id < value){
                if(ptr->left == nullptr){
                    return nullptr;
                }
                value = ptr->left->value;
                ptr = ptr->left.get();
            }
            else{
                if(ptr->right == nullptr){
                    return nullptr;
                }
                value = ptr->right->value;
                ptr = ptr->right.get();
            }
        }
        return ptr;
    }
};