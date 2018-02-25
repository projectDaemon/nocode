#include <iostream>
#include <optional>
#include <functional>


template<typename T>
struct Lazy{
    Lazy(){
    }

    template<typename Func,typename... Args)
    Lazy(Func& f, Args && ... args){

    }

private:
    std::function<T()> func_;
    std::optional<T> value_;
};






int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}