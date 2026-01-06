#include<iostream>

class Strategy{
    public:
        virtual ~Strategy() = default;
        virtual void doAlgorithm() const = 0;

};

class Context{
    private:
        std::unique_ptr<Strategy> strategy_;
    public:
        explicit Context(std::unique_ptr<Strategy> &&strategy = nullptr) : strategy_(std::move(strategy)) {}
        ~Context(){}
        void setStrategy(std::unique_ptr<Strategy> &&strategy){

            strategy_ = std::move(strategy);
        }
        void executeStrategy() const {
            if(strategy_){
                std::cout << "Context: Executing strategy...\n";
                strategy_->doAlgorithm();
            }else {
                std::cout << "Context: No strategy set.\n";
            }
        }
};

class ConcreteStrategyA : public Strategy {
    public:
        void doAlgorithm() const override {
            std::cout << "ConcreteStrategyA: " << "\n";
        }
};

class ConcreteStrategyB : public Strategy {
    public:
        void doAlgorithm() const override {
            std::cout << "ConcreteStrategyB: " << "\n";
        }
};

int main(){
    auto context = std::make_unique <Context>(std::make_unique< ConcreteStrategyA>());
    context->executeStrategy();
    context->setStrategy(std::make_unique<ConcreteStrategyB>());
    context->executeStrategy();
    return 0;
}