#include <iostream>
#include <vector>
using namespace std;

string toRoman(int num) {
    vector<pair<int,string>> values = {
        {1000,"M"}, {900,"CM"}, {500,"D"}, {400,"CD"},
        {100,"C"}, {90,"XC"}, {50,"L"}, {40,"XL"},
        {10,"X"}, {9,"IX"}, {5,"V"}, {4,"IV"},
        {1,"I"}
    };

    string result;

    for (auto &[value, symbol] : values) {
        while (num >= value) {
            result += symbol;
            num -= value;
        }
    }

    return result;
}

int main() {
    int n = 99;

    if (n < 1 || n > 1000) {
        cout << "Out of range\n";
        return 0;
    }

    cout << toRoman(n) << endl;
    return 0;
}