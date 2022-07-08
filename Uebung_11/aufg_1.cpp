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
template< typename Function, typename... Args >
std::thread* create_thread( const std::size_t pin, Function&& magic, Args... args ) {
auto core_count= std::thread::hardware_concurrency();
int core = pin % core_count;
std::cout << "Pinning new thread to " << core << std::endl;
cpu_set_t cpuset;
CPU_ZERO( &cpuset );
CPU_SET( core, &cpuset );
std::thread* t = new std::thread( std::forward< Function >( magic ), args... );
int rc = pthread_setaffinity_np( t->native_handle(), sizeof( cpu_set_t ), &cpuset );
if (rc != 0) {
std::cerr << "Error calling pthread_setaffinity_np: " << rc << "\n";
exit( -10 );
}
return t;
}

auto work = [](std::shared_future< void >* ready_future, bool* ready,std::atomic<std::size_t>* done,int id, std::vector<int>* sumve  ) -> void {
std::cout << "Thread waiting at promise." << std::endl;
ready_future->wait(); // Wait until promised value is ready
std::cout << "Thread working..." << std::endl;
int sum=0;
int a;
std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist6(1,30); 
for(int i=0;i<10;i++){
a = dist6(rng);
sum=sum +a;
std::cout << id<<":"<< a << std::endl;
std::this_thread::sleep_for (std::chrono::seconds(a));
}
sumve->at(id)= sum;
++(*done);
};



void clear_pool( thread_pool* pool ) {
std::cout << "Cleaning pool..." << std::flush;
for ( auto t : *pool ) {
t->join();
delete t;
}
pool->clear();
std::cout << "all clean." << std::endl;
}


int main() {
int thread_number=13;
std::vector<int> sumv;
std::vector<std::chrono::steady_clock::time_point> time_begin;
std::vector<std::chrono::steady_clock::time_point> time_end;
for(int i=0;i<thread_number;i++){
    sumv.emplace_back(0);
}
thread_pool pool;
std::atomic<std::size_t> done = {0};
bool ready = false;
std::promise< void > p;
std::shared_future< void > ready_future( p.get_future( ) );

std::size_t pin = 0;

for ( std::size_t i = 0; i < thread_number; ++i ) {
pool.emplace_back( create_thread( pin++, work, &ready_future,&ready,&done ,i,&sumv) );
time_begin.emplace_back(std::chrono::steady_clock::now());
--done;
}
p.set_value();
while (done != 0) {
using namespace std::chrono_literals;
std::this_thread::sleep_for( 1us );
}
std::cout << "All done!" << std::endl;
for ( int i=0;i<pool.size();i++) {
pool.at(i)->join();
time_end.emplace_back(std::chrono::steady_clock::now());
delete pool.at(i);
}
pool.clear();
int sum_over=0;
for(int i=0;i<thread_number;i++){
std::cout<<"Thread: "<<i<<std::endl;
std::cout<<"waited: "<<sumv.at(i)<<std::endl;
std::cout<<"outside: "<<std::chrono::duration_cast<std::chrono::microseconds>(time_end.at(i) - time_begin.at(i)).count()<<"[µs]" << std::endl;
sum_over=sum_over+sumv.at(i);
}
std::cout<<"Threads waited a total time of "<< sum_over<<std::endl;
return 0;
}
