#include <iostream>
#include <string>
#include <map>
#include <dlfcn.h>
#include <functional>


class DylibHelper{
private:
    void *mod_;
    std::map<std::string,void*> funcs_;
public:
    DylibHelper(){

    }
    ~DylibHelper(){

    }
    bool Load(const std::string & dylibpath){
        mod_ = dlopen(dylibpath.c_str(),RTLD_LAZY);
        if(!mod_){
            return false;
        }
        return true;
    }
    bool Unload(){
        if(mod_){
            if (-1 == dlclose(mod_)){
                return false;
            }
            mod_ = nullptr;
        }
        return true;
    }


    template <typename T>
    std::function<T> GetFunction(const std::string & func_name){
        auto it = funcs_.find(func_name);
        if(it != funcs_.end()){
            return std::function<T>((T*)it->second);
        }
        auto addr = dlsym(mod_,func_name.c_str());
        if(!addr){
            return nullptr;
        }
        funcs_[func_name] = addr;
        return std::function<T>((T*)addr);
    }


    template <typename T, typename... Args>
    typename std::result_of<std::function<T>(Args...)>::type ExecuteFunc(const std::string & func_name,Args&&... args){
        auto f = GetFunction<T>(func_name);
        if(f == nullptr){
            throw "can not find function";
        }
        return f(std::forward<Args>(args)...);
    }
};

int main() {




    std::cout << "Hello, World!" << std::endl;
    return 0;
}