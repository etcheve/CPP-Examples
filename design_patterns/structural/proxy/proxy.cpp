#include<iostream>


class Subject {
    public:
        virtual ~Subject() {}
        virtual void request() const = 0;
};

class RealSubject : public Subject {
    public: 
        void request() const override {
            std::cout << "RealSubject: Handling request.\n";
        }
};

class Proxy : public Subject {
    private: 
        RealSubject* real_subject_;
        bool checkAccess() const {
            // Some real checks should go here.
            std::cout << "Proxy: Checking access prior to firing a real request.\n";
            return true;
        }
        void logAccess() const {
            std::cout << "Proxy: Logging the time of request.\n";
        }   
        public:
        Proxy(RealSubject* real_subject) : real_subject_(real_subject) {}
        void request() const override {
            if (this->checkAccess()) {
                real_subject_->request();
                this->logAccess();
            }
        }

};

void ClientCode(const Subject &subject) {
  // ...
  subject.request();
  // ...
}

int main (){
    RealSubject* real_subject = new RealSubject();
    std::cout << "Client: Executing the client code with a real subject:\n";
    ClientCode(*real_subject);
    std::cout << "Client: Executing the same client code with a proxy:\n";
    Proxy* proxy = new Proxy(real_subject);
    ClientCode(*proxy);
    return 0;
}