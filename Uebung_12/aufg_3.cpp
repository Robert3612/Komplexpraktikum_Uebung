#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <immintrin.h>


int query_intrinsics(std::vector<int>* vec){
std::vector<uint32_t> helpvec(16, 10);
    auto helpreg = _mm512_loadu_si512(veg_with_10s.data());

    int result = 0;
    for (unsigned int i = 0; i < 10000; i += 16) {
        auto helpreg2 = _mm512_loadu_si512(vec->data() + i);
        auto mask = _mm512_cmplt_epu32_mask(helpreg, helpreg2);
        result += _mm_popcnt_u32(mask);
    }
    return result;
}

int query_scalar(std::vector<int>* dataset){
int help=0;


for(int i=0;i<10000;i++){
    if(dataset->at(i)<10){
        help++;
    }
}
return help;
}




int main() {
using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
     std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,100);
std::vector<int> dataset;
dataset.resize(10000);


duration<double, std::milli> ms_scal{};
duration<double, std::milli> ms_intr{};
for(int i=0;i<10;i++){
    for(int i;i<10000;i++){
dataset.at(i)=dist6(rng);
}
auto t1 = high_resolution_clock::now();
int h2 = query_scalar(&dataset);
auto t2 = high_resolution_clock::now();
auto t3 = high_resolution_clock::now();
int h = query_intrinsics(&dataset);
auto t4 = high_resolution_clock::now();
std::cout<<h2<<std::endl;
std::cout<<h<<std::endl;
ms_scal =ms_scal+ t2 - t1;
ms_intr =ms_intr + t4 - t3;
}


std::cout <<"scalar"<< ms_scal.count() << "ms"<<std::endl;
std::cout <<"intr:"<< ms_intr.count() << "ms"<<std::endl;

return 0;

//eigener PC
//          scalar      intr
// -O0      0,134 ms    0,010 ms
// -O1      0,008 ms    0,002 ms
// -O2      0,0077 ms   0,0019 ms
// -O0      0,0074 ms   0,0015 ms
// intr ist immer schneller als scalar


//Assembly-code-scalar
// kein Unterschied zwischen O3 und O2
//kleine Optimierungen von O1 nach O2
// viele Optimierungen von O0 nach O1 (call von vector in O0 existiert nicht mehr)

//Assembly-code-intr
//O0 sehr lang, call zu std::vector existiert 
//ab O1 Befehle wie vpbroadcastd
// kein Unterschied zwischen O3 und O2


//median
//der Median wird nicht so stark von Ausreißern beeinflusst wie der Mittelwert 
}
