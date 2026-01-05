#include <iostream>

class Handler {
    public:
        virtual ~Handler() = default;
        virtual void setNext(Handler* nextHandler) = 0 ;
        virtual void handleRequest(int request) = 0;
};


class basicImplementation : public Handler {
    public:
        void handleRequest(int request) override {
            if (request >= 0 && request < 10){
                std::cout << "basic Implementation handled request " << request << "\n";
            } else if (nextHandler_) {
                nextHandler_->handleRequest(request);
            }
        }
        void setNext(Handler* nextHandler) override {
            nextHandler_ = nextHandler;
        }
    private:
        Handler* nextHandler_ = nullptr;      
    };


    class httpAuthentication : public Handler {
    public:
        void handleRequest(int request) override {
            if (request >= 10 && request < 20){
                std::cout << "HTTP Authentication handled request " << request << "\n";
            } else if (nextHandler_) {
                nextHandler_->handleRequest(request);
            }
        }
        void setNext(Handler* nextHandler) override {
            nextHandler_ = nextHandler;
        }
    private:
        Handler* nextHandler_ = nullptr;      
    };  

    class loggingHandler : public Handler {
    public:
        void handleRequest(int request) override {  
            std::cout << "Logging Handler handled request " << request << "\n";
            if (nextHandler_) {
                nextHandler_->handleRequest(request);
            }
        }
        void setNext(Handler* nextHandler) override {   
            nextHandler_ = nextHandler;
        }
    private:
        Handler* nextHandler_ = nullptr;      
    };  
int main (){
    basicImplementation* basic = new basicImplementation();
    httpAuthentication* httpAuth = new httpAuthentication();
    loggingHandler* logger = new loggingHandler();  
    basic->setNext(httpAuth);
    httpAuth->setNext(logger);  
    int requests[] = {2, 5, 14, 22, 18, 3, 27, 15};
    for (int request : requests){
        basic->handleRequest(request);
    }
    delete basic;
    delete httpAuth;
    delete logger;
    return 0;
}