#include "adapter.hpp"
#include <iostream>

int main() {
    LegacyMarketData* legacyMarketData = new LegacyMarketData();
    TargetMarketData* adapter = new AdapterMarketData(legacyMarketData);
    double aaplPrice = adapter->fetchPrice("AAPL");
    double googlPrice = adapter->fetchPrice("GOOGL");
    std::cout << "AAPL Price: " << aaplPrice << "\n";
    std::cout << "GOOGL Price: " << googlPrice << "\n";

    delete adapter;
    delete legacyMarketData;

    return 0;
};
