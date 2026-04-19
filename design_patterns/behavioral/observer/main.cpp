#include <iostream>
#include <string>
#include <list>
class Observer {
    public:     
        virtual ~Observer() = default;
        virtual void update(const std::string &message_from_subject) = 0;
};

class Subject {
    public:
        virtual ~Subject() = default;
        virtual void attach(Observer *observer) = 0;
        virtual void detach(Observer *observer) = 0;
        virtual void notify() = 0;
};


class ConcreteSubject : public Subject {
    public:
        virtual ~ConcreteSubject() {
            std::cout << "Goodbye, I was the Subject.\n";
        }
        void attach(Observer *observer) override {
            list_observer_.push_back(observer);
        }
        void detach(Observer *observer) override {
            std::cout << "ConcreteSubject: Removing an observer from the list.\n";
            list_observer_.remove(observer);
        }
        void notify() override {
            howManyObservers();
            for (auto* observer : std::list<Observer*>(list_observer_)) {
                observer->update(message_);
            }
        }
        void createMessage(std::string message = "Empty") {
            message_ = message;
            notify();
        }
        void howManyObservers() {
            std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
        }
    private:
        std::list<Observer *> list_observer_;
        std::string message_;
};


class ConcreteObserver : public Observer {
    public:
        ConcreteObserver(Subject *subject, int number) : subject_(subject), number_(number) {
            subject_->attach(this);
            std::cout << "Hi, I'm a Observer number \"" << number_ << "\".\n";
        }
        virtual ~ConcreteObserver() {
            std::cout << "Goodbye, I was the Observer \"" << number_ << "\".\n";
        }
        void update(const std::string &message_from_subject) override {
            message_from_subject_ = message_from_subject;
            // I only want to be notified once
            subject_->detach(this);
            printInfo();
        }
        void removeMeFromTheList() {
            subject_->detach(this);
            std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
        }
        void printInfo() {
            std::cout << "Observer \"" << number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
        }
    private:
        std::string message_from_subject_;
        Subject *subject_;
        int number_;
};


int main() {
    ConcreteSubject *subject = new ConcreteSubject;
    ConcreteObserver *observer1 = new ConcreteObserver(subject, 1);
    ConcreteObserver *observer2 = new ConcreteObserver(subject, 2);
    ConcreteObserver *observer3 = new ConcreteObserver(subject, 3);
    ConcreteObserver *observer4;
    ConcreteObserver *observer5;

    subject->createMessage("Hello World! :D");

    subject->createMessage("The weather is hot today! :p");
    observer4 = new ConcreteObserver(subject, 4);
    observer5 = new ConcreteObserver(subject, 5);

    subject->createMessage("My new car is great! ;)");

    delete observer5;
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
    delete subject;

    return 0;
}