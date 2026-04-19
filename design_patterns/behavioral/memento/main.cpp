#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Memento {
    public:
    virtual ~Memento() = default;
    virtual std::string getState() const = 0;
    virtual std::string getName() const = 0;
    virtual std::string getDate() const = 0;
};

class concreteMemento : public Memento {
    private:
        std::string state_;
        std::string date_;
    public:
        concreteMemento(const std::string &state) : state_(state){
        }
        std::string getState() const override {
            return state_;
        }
        std::string getName() const override {
            return state_.substr(0, 9) + "...";
        }
        std::string getDate() const override {
            return date_;
        }
};

// Originator class have an important state we want to save and have a way to restore it
class Originator {
    private:
        std::string state_;
        std::string generateRandomString(int length = 10) {
            const char charset[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
            std::string result;
            for (int i = 0; i < length; ++i) {
                result += charset[rand() % (sizeof(charset) - 1)];
            }
            return result;
        }

    public:
        Originator(const std::string &state) : state_(state){
            std::cout << "Originator: Initial state is " << state_ << "\n";
        }
        void changeState() {
            std::cout << "Originator: Changing state from " << state_;
            state_ = generateRandomString(10);
            std::cout << " to " << state_ << "\n";
        }


        std::unique_ptr<Memento> save() {
            return std::make_unique<concreteMemento>(state_);
        }
        void restore(std::unique_ptr<Memento> memento) {
            state_ = memento->getState();
            std::cout << "Originator: State restored to " << state_ << "\n";
        }


};

class History{
    private:
        std::vector<std::unique_ptr<Memento>> mementos_;
        std::shared_ptr<Originator> originator_;

    public:
        History(std::shared_ptr<Originator> originator) : originator_(originator) {}
        void backUp(){
            mementos_.push_back(originator_->save());
        }
        void history() const {
            
            for (const auto &memento : mementos_){
                std::cout << memento->getName() << "\n";
            }
        }

        void undo(){
            if (mementos_.empty()){
                return ;
            }
            auto memento = std::move(mementos_.back());
            mementos_.pop_back();
            std::cout << "History: Restoring state to " << memento->getName() << "\n";
            originator_->restore(std::move(memento));
        }
};

int main (){
    std::cout << "Memento Pattern Example\n\n";
    auto originator =  std::make_shared<Originator>("Initial State");
    auto history =  std::make_unique<History>(originator);
    history->backUp();
    originator->changeState();
    history->backUp();
    originator->changeState();
    history->undo();

    return 0;
}