

#include <iostream>
#include "ThreadPool.hpp"


void Test(){
    ThreadPool pool(2);

    std::thread thread1([&pool]{
        for(int i = 0; i < 10; i++){
            auto id = std::this_thread::get_id();
            pool.AddTask([id]{
                cout << "sync thread1 thread id = "<< id<<endl;
            });
        }
    });

    std::thread thread2([&pool]{
        for(int i = 0; i < 10; i++){
            auto id = std::this_thread::get_id();
            pool.AddTask([id]{
                cout << "sync thread2 thread id = "<< id<<endl;
            });
        }
    });

    this_thread::sleep_for(std::chrono::seconds(2));

    getchar();
    pool.Stop();
    thread1.join();
    thread2.join();
}

int main() {
    Test();

    return 0;
}