#include <iostream>
#include <memory>

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() const = 0;
};

class SimpleCommand : public Command {
public:
    void execute() const override {
        std::cout << "SimpleCommand: executing.\n";
    }
};

class Receiver {
public:
    void doSomething(const std::string& a) {
        std::cout << "Receiver: working on (" << a << ").\n";
    }
    void doSomethingElse(const std::string& b) {
        std::cout << "Receiver: also working on (" << b << ").\n";
    }
};

class ReceiverCommand : public Command {
public:
    ReceiverCommand(Receiver* receiver, const std::string& a, const std::string& b)
        : receiver_(receiver), a_(a), b_(b) {}

    void execute() const override {
        std::cout << "ReceiverCommand: delegating to Receiver.\n";
        receiver_->doSomething(a_);
        receiver_->doSomethingElse(b_);
    }

private:
    Receiver* receiver_;
    std::string a_, b_;
};

class Invoker {
public:
    void setOnStart(std::unique_ptr<Command> cmd)  { onStart_  = std::move(cmd); }
    void setOnFinish(std::unique_ptr<Command> cmd) { onFinish_ = std::move(cmd); }

    void run() {
        std::cout << "Invoker: before start.\n";
        if (onStart_)  onStart_->execute();
        std::cout << "Invoker: doing the important work...\n";
        std::cout << "Invoker: after finish.\n";
        if (onFinish_) onFinish_->execute();
    }

private:
    std::unique_ptr<Command> onStart_;
    std::unique_ptr<Command> onFinish_;
};

int main() {
    Receiver receiver;
    Invoker invoker;
    invoker.setOnStart(std::make_unique<SimpleCommand>());
    invoker.setOnFinish(std::make_unique<ReceiverCommand>(&receiver, "Send email", "Save report"));
    invoker.run();
    return 0;
}
