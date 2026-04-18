#include "adapter.hpp"
#include <iostream>
#include <memory>

int main() {
    auto legacyMarketData = std::make_unique<LegacyMarketData>();
    std::unique_ptr<TargetMarketData> adapter = std::make_unique<AdapterMarketData>(legacyMarketData.get());

    std::cout << "AAPL Price: " << adapter->fetchPrice("AAPL") << "\n";
    std::cout << "GOOGL Price: " << adapter->fetchPrice("GOOGL") << "\n";
}
