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
#include <iomanip>
#include <immintrin.h>
void mmult(float *r, float const *a, float const *b, int N) {
auto hadd = [](__m256 vec) {float result=0.0; for(int i=0; i < 8; ++i){ result += vec[i]; } return result; };
// assuming N is a multiple of 8
for (int row = 0; row < N; ++row) {
auto a_data = a + (row * N);
for (int col = 0; col < N; ++col) {
auto b_data = b + (col * N);
auto val_vec = _mm256_setzero_ps();
for (int idx = 0; idx < N; ++idx) {
val_vec = _mm256_add_ps(
val_vec,
_mm256_mul_ps(
_mm256_loadu_ps(&a_data[idx]),
_mm256_loadu_ps(&b_data[idx])
)
);
}
r[(row * N) + col] = hadd(val_vec);
}
}
}


int main() {
using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
     std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,10);   
float Mat1[100][100];
    float Mat2[100][100];
    float Mat3[100][100];

for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 10; j++) {
            Mat1[i][j]= dist6(rng);
            Mat2[i][j]= dist6(rng);
        }
    }

auto t1 = high_resolution_clock::now();
mmult(&Mat3[0][0],&Mat1[0][0],&Mat2[0][0], 100);
auto t2 = high_resolution_clock::now();

duration<double, std::milli> ms_double = t2 - t1;

for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 10; j++) {
           std::cout << std::left << std::setw(20) << Mat3[i][j];
        }
         std::cout << std::endl;
    }


    std::cout << ms_double.count() << "ms"<<std::endl;
    return 0;




//-O0 : 3ms
//-O1 : 0,77 ms
//-O2 : 0,75 ms 
//-O3 : 0,73 ms 
//-Ofast : 0,26 ms
//-Og: 0,88 ms
// generell Ausreisser bis zu 0,83 ms

}
