#include <iostream>

class Command{
    public: 
        virtual ~Command() = default;
        virtual void execute() const = 0;           
};

class simpleCommand : public Command{

    public:
        void execute() const override {
            std::cout << "Simple Command: Executing with payload: " << "\n";
        }
};


// Receiver class containes some business logic,  
class Receiver {
 public:
  void DoSomething(const std::string &a) {
    std::cout << "Receiver: Working on (" << a << ".)\n";
  }
  void DoSomethingElse(const std::string &b) {
    std::cout << "Receiver: Also working on (" << b << ".)\n";
  }
};

class ReceiverCommand : public Command {
    private:
        Receiver* receiver_;
        std::string a_;
        std::string b_;
    public:
        ReceiverCommand(Receiver* receiver, const std::string &a, const std::string &b) 
            : receiver_(receiver), a_(a), b_(b) {}
        
        void execute() const override {
            std::cout << "Receiver Command: Delegating to Receiver.\n";
            receiver_->DoSomething(a_);
            receiver_->DoSomethingElse(b_);
        }
};

class Invoker {
    private:
        Command* onStart_;
        Command* onFinish_;
    public:
        ~Invoker() {
            delete onStart_;
            delete onFinish_;   
        }
        void setOnStart(Command* command) {
            onStart_ = command;
        }
        void setOnFinish(Command* command) {
            onFinish_ = command;
        }
        void doSomethingImportant() {
            std::cout << "Invoker: Does anybody want something done before I begin?\n";
            if (onStart_) {
                onStart_->execute();
            }
            std::cout << "Invoker: ...doing something really important...\n";
            std::cout << "Invoker: Does anybody want something done after I finish?\n";
            if (onFinish_) {
                onFinish_->execute();
            }
        }
};

int main (){
    Invoker* invoker = new Invoker();
    invoker->setOnStart(new simpleCommand());
    Receiver* receiver = new Receiver();
    invoker->setOnFinish(new ReceiverCommand(receiver, "Send email", "Save report"));
    invoker->doSomethingImportant();

    delete receiver;
    delete invoker;
    return 0;
}