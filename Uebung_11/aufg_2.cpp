#include <iostream>
#include <string>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <vector>
#include <pthread.h>
#include <random>
#include <chrono>
#include <future>

typedef std::vector< std::thread* > thread_pool;
std::vector<unsigned long long> data(10000, 35643456);


void primeFactors(unsigned long long n)
{
    while (n % 2 == 0)
    {
        //std::cout << 2 << " ";
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            //std::cout << i << " ";
            n = n/i;
        }
    }
 
    if (n > 2)
        //std::cout << n << " ";
        n;
}

auto work= [] (int begin,int end)-> void{
    for(int i=begin;i<end;i++){
        primeFactors(data.at(i));
    }
};

void start_threading( int n){
int step=data.size() /n;
int begin=0;
int end=begin+step;
std::vector<std::thread*> pool;
std::chrono::steady_clock::time_point time_begin = std::chrono::steady_clock::now();
for(int i=0;i<n;i++){
    pool.push_back(new std::thread( work, begin,end ));
    begin=end;
    end=begin+step;
}
for (auto& thread : pool) {
    thread->join();
}
std::chrono::steady_clock::time_point time_end = std::chrono::steady_clock::now();
std::cout << "Time difference multiple thread= " << std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_begin).count() << "[µs]" << std::endl;
}

void start_threading2( int n){
int step=data.size() /n;
int begin=0;
int end=begin+step;
std::vector<std::thread*> pool;
int core = 0;
auto core_count= std::thread::hardware_concurrency();
std::chrono::steady_clock::time_point time_begin = std::chrono::steady_clock::now();
for(int i=0;i<n;i++){
    cpu_set_t cpuset;
    CPU_ZERO( &cpuset );
    CPU_SET( core, &cpuset );
    std::thread* t = new std::thread( work, begin,end );
    int rc = pthread_setaffinity_np( t->native_handle(), sizeof( cpu_set_t ), &cpuset );
    if (rc != 0) {
    std::cerr << "Error calling pthread_setaffinity_np: " << rc << "\n";
    exit( -10 );
    }
    core = (core + 1) % core_count;
    pool.push_back(t);
    begin=end;
    end=begin+step;
}
for (auto& thread : pool) {
    thread->join();
}
std::chrono::steady_clock::time_point time_end = std::chrono::steady_clock::now();
std::cout << "Time difference multiple thread with pinning= " << std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_begin).count() << "[µs]" << std::endl;
}

int main() {
    //threadanzahl
    int n=10;
std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
for(int i=0;i<data.size();i++){
    primeFactors(data.at(i));
}
std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
std::cout << "Time difference singele thread = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;

start_threading( n);

start_threading2( n);
//bei einer kleinen Anzahl von Werten(zB 1000) ist die single implementation schneller
//pinning ist schneller als kein pinning, aber beide Arten sind viel schneller als single bei einer großen Anzahl von Werten
//die Zeiten für Threads werden mit steigender Threadanzahl immer kürzer jedoch, steigen sie ab einer bestimmten Anzahl wieder stark
//ab dieser Anzahl ist der Overhead zu groß
//die Zeiten nähern sich dem 1/n erreichen dieses aber nie
//durch den Overhead ist eine kleine Anzahl an Threads näher an 1/n
return 0;
}