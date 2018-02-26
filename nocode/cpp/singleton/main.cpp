#include <iostream>


template <typename T>
class Singleton{
public:
    template<typename... Args>
    static T* Instance(Args&&... args){
        if(inst_ == nullptr){
            inst_ = new T(std::forward<Args>(args)...);
        }
        return inst_;
    }

    static T *GetInstance(){
        if(inst_ == nullptr){
            return nullptr;
        }
        return inst_;
    }

    static void Destroy(){
        if(inst_ == nullptr)
            return;
        delete inst_;
        inst_ = nullptr;
    }
private:
    static T *inst_;
};
template <typename T>
T* Singleton<T>::inst_ = nullptr;


//////


struct A{
    A(const std::string&){std::cout << "lvalue"<<std::endl;}
    A(std::string&&){std::cout << "rvalue"<<std::endl;}
};

struct B{
    B(const std::string&){std::cout << "lvalue"<<std::endl;}
    B(std::string&&){std::cout << "rvalue"<<std::endl;}
};




int main() {
    std::string str = "hello";
    Singleton<A>::Instance(str);
    Singleton<B>::Instance(std::move(str));

    Singleton<A>::Destroy();
    Singleton<B>::Destroy();
    return 0;
}