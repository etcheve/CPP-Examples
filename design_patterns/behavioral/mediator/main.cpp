#include <iostream>

class BaseComponent;
class Mediator{
    public: 
    virtual void notify(BaseComponent* sender, const std::string &event) = 0;
};

class BaseComponent {
    protected:
        Mediator* mediator_;
    public:
        BaseComponent(Mediator* mediator = nullptr) : mediator_(mediator) {}
        void setMediator(Mediator* mediator){
            mediator_ = mediator;
        }
        virtual ~BaseComponent() = default;
};

class Component1 : public BaseComponent {
    public: 
        void doA(){
            std::cout << "Component 1 does A.\n";
            mediator_->notify(this, "A");
        }
        void doB(){
            std::cout << "Component 1 does B.\n";
            mediator_->notify(this, "B");
        }
};

class Component2 : public BaseComponent {
    public: 
        void doC(){
            std::cout << "Component 2 does C.\n";
            mediator_->notify(this, "C");
        }
        void doD(){
            std::cout << "Component 2 does D.\n";
            mediator_->notify(this, "D");
        }
};


class ConcreteMediator : public Mediator {
    private:
        Component1* component1_;
        Component2* component2_;
    public:
        ConcreteMediator(Component1* c1, Component2* c2) : component1_(c1), component2_(c2){
            component1_->setMediator(this);
            component2_->setMediator(this);
        }
        void notify(BaseComponent* , const std::string &event) override {
            if (event == "A"){
                std::cout << "Mediator reacts on A and triggers following operations:\n";
                component2_->doC();
            } else if (event == "D"){
                std::cout << "Mediator reacts on D and triggers following operations:\n";
                component1_->doB();
                component2_->doC();
            }
        }
};

int main() {
    Component1* c1 = new Component1();
    Component2* c2 = new Component2();
    ConcreteMediator* mediator = new ConcreteMediator(c1, c2);

    std::cout << "Client triggers operation A.\n";
    c1->doA();
    std::cout << "\n";
    std::cout << "Client triggers operation D.\n";
    c2->doD();

    delete mediator;
    delete c1;
    delete c2;
    return 0;
}