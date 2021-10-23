#include <memory>
#include <iostream>
#include <fstream>

struct binary_tree_node{
    int val;
    std::unique_ptr<binary_tree_node> left;
    std::unique_ptr<binary_tree_node> right;

    binary_tree_node():val(0),left(nullptr), right(nullptr){}
    binary_tree_node(int x):val(x),left(nullptr), right(nullptr){}
};

class binary_tree{
    private:
        using node = binary_tree_node;
        std::unique_ptr<node> _root;
        int right = 1;
        int left = 0;
        void _print(const std::unique_ptr<node> &ptr);
        void _insert(std::unique_ptr<node> &ptr,const int& val);
        bool _remove(const std::unique_ptr<node> &ptr,const int& val);
        bool _contains(const std::unique_ptr<node> &ptr,const int& val);
        int  _find_min(const std::unique_ptr<node> &ptr,const int& val);
    public:
        binary_tree();
        void print(){_print(_root);};
        void insert(int val){_insert(_root, val);}
        bool remove(int val){return _remove(_root, val);}
        bool contains(int val){return _contains(_root, val);}
        int  find_min_right(){return _find_min(_root,  right);}
};

binary_tree::binary_tree(){
    _root = nullptr;
}

void binary_tree::_print(const std::unique_ptr<node> &ptr){
    if(ptr == nullptr){
        return;
    }else{
        _print(ptr->left);
        std::cout << ptr->val << " ";
        _print(ptr->right);
    }
}
                                                           
int  binary_tree::_find_min(const std::unique_ptr<node> &ptr,const int& val){
    if(val == 1){

    }else{

    }
}



void binary_tree::_insert(std::unique_ptr<node> &ptr,const int& val){
    if(ptr == nullptr){
        ptr = std::make_unique<node>(val);
    } else{
        val < ptr->val ? 
                _insert(ptr->left, val):
                    _insert(ptr->right, val);
    }
}

bool binary_tree::_remove(const std::unique_ptr<node> &ptr,const int& val){

}

bool binary_tree::_contains(const std::unique_ptr<node> &ptr,const int& val){
    if(ptr == nullptr){
        return false;
    }else {
        if(ptr->val == val){
            return true;
        }else{
            return (val < ptr->val?
            _contains(ptr->left, val):
            _contains(ptr->right, val));
        }
    }
}

int main(){
    binary_tree bt;
    bt.insert(5);
    bt.insert(3);
    bt.insert(2);
    bt.insert(12);
    bt.insert(1);
    bt.insert(10);

    std::cout << bt.contains(10);
    return 0;
}