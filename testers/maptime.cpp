#include <iostream>
#include <chrono>
#include <map>
#include <unordered_map>

// #define map unordered_map

using namespace std;
using namespace std::chrono;

const int N = 100000000;

void benchmark_clear() {
    map<int, int> m;
    for (int i = 0; i < N; ++i) m[i] = i;

    auto start = high_resolution_clock::now();
    m.clear();
    auto end = high_resolution_clock::now();

    cout << "clear() time: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;
}

void benchmark_assign_empty() {
    map<int, int> m;
    for (int i = 0; i < N; ++i) m[i] = i;

    auto start = high_resolution_clock::now();
    m = {};
    auto end = high_resolution_clock::now();

    cout << "assign {} time: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;
}

void benchmark_swap() {
    map<int, int> m;
    for (int i = 0; i < N; ++i) m[i] = i;

    auto start = high_resolution_clock::now();
    map<int, int>().swap(m);
    auto end = high_resolution_clock::now();

    cout << "swap() time: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;
}

int main() {
    cout << "Benchmark for unordered_map with " << N << " elements:\n\n";

    benchmark_clear();
    benchmark_assign_empty();
    benchmark_swap();

    return 0;
}

