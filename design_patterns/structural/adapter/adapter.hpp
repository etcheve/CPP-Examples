#pragma once
#include <string>
// LegacyMarketData is an example of an external applicationm that we want to adapt
class LegacyMarketData {
    public:
    double getPrice(const std::string &symbol) {
        // Simulate fetching price from legacy system
        if (symbol == "AAPL") return 150.0;
        if (symbol == "GOOGL") return 2800.0;
        return 0.0;
    }
};

// TargetMarketData is the interface our application expects
class TargetMarketData {
    public:
    virtual ~TargetMarketData() = default;
    virtual double fetchPrice(const std::string &symbol) = 0;
};

// AdapterMarketData adapts LegacyMarketData to the TargetMarketData interface
class AdapterMarketData : public TargetMarketData {
    private:
    LegacyMarketData* legacyMarketData_;  
    public:
    AdapterMarketData(LegacyMarketData* legacyMarketData) : legacyMarketData_(legacyMarketData) {}
    double fetchPrice(const std::string &symbol) override {
        return legacyMarketData_->getPrice(symbol);
    }
};

