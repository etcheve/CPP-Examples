// https://leetcode.com/problems/number-of-orders-in-the-backlog/description/
#include<vector>
#include <iostream>
#include<string>
#include <set>
using namespace std;
struct Order {
    Order(int pr, int am){
        price = pr;
        amount =am;
    }
    int price;
    mutable int amount;
};

struct CompareBuy {
    bool operator()(const Order& a, const Order& b) const {
        return a.price > b.price; // highest price first for buy orders
    }
};

struct CompareSell {
    bool operator()(const Order& a, const Order& b) const {
        return a.price < b.price; // lowest price first for sell orders
    }
};

class Solution {
private:
    const long long MOD = 1000000007;
    const int PRICEIDX = 0; 
    const int AMOUNTIDX = 1; 
    const int ORDTYPEIDX = 2; 
    const int BUY = 0;
    const int SELL = 1;

    std::multiset<Order,CompareBuy> buyOrders_;
    std::multiset<Order,CompareSell> sellOrders_;

public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        for (auto order : orders){
            if(order[ORDTYPEIDX] == BUY){
                handleBuy(order);
            }
            else{
                handleSell(order);          
            }
        }
        return calculateTotalOrders();
    }

    void handleBuy(vector<int>& order) {
    while (!sellOrders_.empty() && order[AMOUNTIDX] > 0) {
        auto bestSell = sellOrders_.begin();
        if (bestSell->price > order[PRICEIDX]) break; // can't match

        if (bestSell->amount > order[AMOUNTIDX]) {
            bestSell->amount -= order[AMOUNTIDX];
            order[AMOUNTIDX] = 0;
            break; // fully matched
        } else {
            order[AMOUNTIDX] -= bestSell->amount;
            sellOrders_.erase(bestSell); // remove fully consumed sell order
        }
    }

    // Insert remaining buy order if any
    if (order[AMOUNTIDX] > 0) {
        buyOrders_.insert(Order(order[PRICEIDX], order[AMOUNTIDX]));
    }
}

void handleSell(vector<int>& order) {
    while (!buyOrders_.empty() && order[AMOUNTIDX] > 0) {
        auto bestBuy = buyOrders_.begin();
        if (bestBuy->price < order[PRICEIDX]) break; // can't match

        if (bestBuy->amount > order[AMOUNTIDX]) {
            bestBuy->amount -= order[AMOUNTIDX];
            order[AMOUNTIDX] = 0;
            break; // fully matched
        } else {
            order[AMOUNTIDX] -= bestBuy->amount;
            buyOrders_.erase(bestBuy); // remove fully consumed buy order
        }
    }

    // Insert remaining sell order if any
    if (order[AMOUNTIDX] > 0) {
        sellOrders_.insert(Order(order[PRICEIDX], order[AMOUNTIDX]));
    }
}


    int calculateTotalOrders(){
        long long total = 0;
        for (auto order : buyOrders_){
            total += order.amount;
        }
        for (auto order : sellOrders_){
            total += order.amount;
        }
        return total % MOD;
    }
};