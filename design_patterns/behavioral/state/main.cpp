#include<iostream>

class Context;

class State {
    protected:
        Context* context_;

    public:
        ~State() = default;
        void setContext(Context* context){
            context_ = context;
        }
        virtual void handle() = 0;
};

class Context {
    private: 
        State* state_;
    public:
        ~Context(){}
        Context(State* state) : state_(nullptr){
            transitionTo(state);
        }

        void transitionTo(State* state){
            std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
            state_ = state;
            state_->setContext(this);
        }

        void request(){
            state_->handle();
        }

};
class ConcreteStateB : public State {
    public:
        void handle() override ;
};
class ConcreteStateA : public State {
    public:
        void handle() override {
            std::cout << "ConcreteStateA handles request.\n";
            std::cout << "ConcreteStateA wants to change the state of the context.\n";
            context_->transitionTo(new ConcreteStateB());
        }
};


void ConcreteStateB::handle()  {
        std::cout << "ConcreteStateB handles request.\n";
        std::cout << "ConcreteStateB wants to change the state of the context.\n";
        context_->transitionTo(new ConcreteStateA());
    }


int main(){
    Context* context = new Context(new ConcreteStateA());
    context->request(); 

    delete context;
}