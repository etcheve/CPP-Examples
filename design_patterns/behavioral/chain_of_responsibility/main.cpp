#include <iostream>

class Handler {
public:
    virtual ~Handler() = default;
    virtual Handler* setNext(Handler* next) = 0;
    virtual void handleRequest(int request) = 0;
};

// AbstractHandler eliminates the repeated nextHandler_ / setNext boilerplate.
class AbstractHandler : public Handler {
public:
    Handler* setNext(Handler* next) override {
        next_ = next;
        return next;
    }
protected:
    Handler* next_ = nullptr;
};

class BasicHandler : public AbstractHandler {
public:
    void handleRequest(int request) override {
        if (request >= 0 && request < 10) {
            std::cout << "BasicHandler handled request " << request << "\n";
        } else if (next_) {
            next_->handleRequest(request);
        }
    }
};

class HttpAuthHandler : public AbstractHandler {
public:
    void handleRequest(int request) override {
        if (request >= 10 && request < 20) {
            std::cout << "HttpAuthHandler handled request " << request << "\n";
        } else if (next_) {
            next_->handleRequest(request);
        }
    }
};

class LoggingHandler : public AbstractHandler {
public:
    void handleRequest(int request) override {
        std::cout << "LoggingHandler handled request " << request << "\n";
        if (next_) next_->handleRequest(request);
    }
};

int main() {
    BasicHandler basic;
    HttpAuthHandler httpAuth;
    LoggingHandler logger;

    basic.setNext(&httpAuth)->setNext(&logger);

    int requests[] = {2, 5, 14, 22, 18, 3, 27, 15};
    for (int request : requests) {
        basic.handleRequest(request);
    }
    return 0;
}
