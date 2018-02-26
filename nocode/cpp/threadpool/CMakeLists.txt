cmake_minimum_required(VERSION 3.9)
project(threadpool)

set(CMAKE_CXX_STANDARD 11)

add_executable(threadpool main.cpp SyncQueue.hpp ThreadPool.hpp)