#include <array>
#include <iostream>

// constexpr function: evaluated at compile time when called with constant args
constexpr long long factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

constexpr int fibonacci(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// constexpr class: usable in constant expressions
class Vec2 {
public:
    constexpr Vec2(double x, double y) : x_(x), y_(y) {}
    constexpr Vec2 operator+(const Vec2& o) const { return {x_ + o.x_, y_ + o.y_}; }
    constexpr Vec2 operator*(double s)      const { return {x_ * s, y_ * s}; }
    constexpr double x() const { return x_; }
    constexpr double y() const { return y_; }
private:
    double x_, y_;
};

// if constexpr: compile-time branch selection, dead branch is not compiled
template <typename T>
void describe(const T& v) {
    if constexpr (std::is_integral_v<T>)
        std::cout << "integral: " << v << "\n";
    else if constexpr (std::is_floating_point_v<T>)
        std::cout << "floating: " << v << "\n";
    else
        std::cout << "other\n";
}

// compile-time lookup table built with constexpr
constexpr std::array<int, 10> make_squares() {
    std::array<int, 10> arr{};
    for (int i = 0; i < 10; ++i) arr[i] = i * i;
    return arr;
}

int main() {
    // --- constexpr functions ---
    std::cout << "--- compile-time evaluation ---\n";
    constexpr long long f10 = factorial(10);
    constexpr int       fib15 = fibonacci(15);
    std::cout << "10! = " << f10 << "\n";
    std::cout << "fib(15) = " << fib15 << "\n";

    // still works at runtime with non-const args
    int n;
    std::cout << "enter n: ";
    std::cin >> n;
    std::cout << n << "! = " << factorial(n) << "\n";

    // --- constexpr class ---
    std::cout << "\n--- constexpr class ---\n";
    constexpr Vec2 a{1.0, 2.0};
    constexpr Vec2 b{3.0, 4.0};
    constexpr Vec2 c = (a + b) * 0.5;
    std::cout << "midpoint: (" << c.x() << ", " << c.y() << ")\n";

    // --- if constexpr ---
    std::cout << "\n--- if constexpr ---\n";
    describe(42);
    describe(3.14);
    describe("text");

    // --- compile-time table ---
    std::cout << "\n--- constexpr lookup table ---\n";
    constexpr auto squares = make_squares();
    for (int i = 0; i < 10; ++i)
        std::cout << i << "^2 = " << squares[i] << "\n";
}
