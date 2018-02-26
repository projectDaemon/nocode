#include <iostream>
using namespace std;


template <class... T>
void f(T... args){
    cout << sizeof...(args)<<endl;
}


template <typename T>
void print(T t){
    cout << "last "<< t<<endl;
}

template <typename T,typename...Args>
void print(T head,Args... rest){
    cout << "param "<<head<<endl;
    print(rest...);
};


int main() {
    f(1,2,3,4);

    print(1,2,3,4);
    return 0;
}