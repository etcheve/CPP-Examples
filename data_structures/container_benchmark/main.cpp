#include <algorithm>
#include <array>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <list>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

// TotalSize = total bytes per element (key included). Must be >= 4.
template<size_t TotalSize>
struct Element {
    static_assert(TotalSize >= sizeof(int), "Element size must be >= 4 bytes");
    int key = 0;
    std::array<char, TotalSize - sizeof(int)> padding{};

    bool operator<(const Element& o)  const { return key < o.key; }
    bool operator==(const Element& o) const { return key == o.key; }
};

using Clock = std::chrono::high_resolution_clock;
using Nanos = std::chrono::duration<double, std::nano>;

static constexpr int RUNS = 7;

// Runs fn RUNS times, drops min and max, returns average in nanoseconds.
template<typename Fn>
double measure_ns(Fn&& fn) {
    std::array<double, RUNS> samples;
    for (int i = 0; i < RUNS; ++i) {
        auto t0 = Clock::now();
        fn();
        samples[i] = Nanos(Clock::now() - t0).count();
    }
    std::sort(samples.begin(), samples.end());
    double sum = 0;
    for (int i = 1; i < RUNS - 1; ++i) sum += samples[i];
    return sum / (RUNS - 2);
}

template<size_t S>
double bench_vector(int n) {
    std::vector<Element<S>> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) v.push_back({i});
    const int target = n / 2;
    volatile bool sink = false;
    return measure_ns([&] {
        sink = std::find_if(v.begin(), v.end(),
            [target](const auto& e) { return e.key == target; }) != v.end();
    });
}

template<size_t S>
double bench_list(int n) {
    std::list<Element<S>> l;
    for (int i = 0; i < n; ++i) l.push_back({i});
    const int target = n / 2;
    volatile bool sink = false;
    return measure_ns([&] {
        sink = std::find_if(l.begin(), l.end(),
            [target](const auto& e) { return e.key == target; }) != l.end();
    });
}

template<size_t S>
double bench_set(int n) {
    std::set<Element<S>> s;
    for (int i = 0; i < n; ++i) s.insert(Element<S>{i});
    const Element<S> target{n / 2};
    volatile bool sink = false;
    return measure_ns([&] {
        sink = s.find(target) != s.end();
    });
}

template<size_t S>
double bench_umap(int n) {
    std::unordered_map<int, Element<S>> m;
    m.reserve(n);
    for (int i = 0; i < n; ++i) m[i].key = i;
    const int target = n / 2;
    volatile bool sink = false;
    return measure_ns([&] {
        sink = m.find(target) != m.end();
    });
}

static std::string fmt(double ns) {
    std::ostringstream oss;
    oss << std::fixed;
    if      (ns < 1e3) { oss << std::setprecision(1) << ns         << " ns"; }
    else if (ns < 1e6) { oss << std::setprecision(2) << ns / 1e3   << " us"; }
    else               { oss << std::setprecision(2) << ns / 1e6   << " ms"; }
    return oss.str();
}

template<size_t S>
void run_suite(const std::vector<int>& ns) {
    std::cout << "\n=== Element size: " << S << " bytes ===\n";
    std::cout << std::left << std::setw(18) << "Container";
    for (int n : ns)
        std::cout << std::right << std::setw(14) << ("N=" + std::to_string(n));
    std::cout << "\n" << std::string(18 + 14 * (int)ns.size(), '-') << "\n";

    auto row = [&](const std::string& name, auto bench_fn) {
        std::cout << std::left << std::setw(18) << name;
        for (int n : ns)
            std::cout << std::right << std::setw(14) << fmt(bench_fn(n));
        std::cout << "\n";
    };

    row("vector",        [](int n) { return bench_vector<S>(n); });
    row("list",          [](int n) { return bench_list<S>(n); });
    row("set",           [](int n) { return bench_set<S>(n); });
    row("unordered_map", [](int n) { return bench_umap<S>(n); });
}

int main() {
    const std::vector<int> ns = {1'000, 10'000, 100'000, 1'000'000};

    run_suite<8>(ns);
    run_suite<64>(ns);
    run_suite<256>(ns);
    run_suite<1024>(ns);

    return 0;
}
