#include<iostream>
#include <string>
#include <unordered_map>


struct SharedState{
        SharedState(std::string model = "" , std::string color = "" , std::string company = "")
            : model_(model), color_(color), company_(company) {}


        friend std::ostream& operator<<(std::ostream &os, const SharedState& s){
            os << "[Model: " << s.model_ << ", Color: " << s.color_ << ", Company: " << s.company_ << "]";
            return os;  
        }    
        std::string getKey() const{
            return model_ + "_" + color_ + "_" + company_;  
        }

        std::string model_;
        std::string color_;
        std::string company_;

};


struct UniqueState{
    public:
        UniqueState(std::string owner = "", std::string licensePlate = "")
            : owner_(owner), licensePlate_(licensePlate) {}

        friend std::ostream& operator<<(std::ostream &os, const UniqueState& u){
            os << "[Owner: " << u.owner_ << ", License Plate: " << u.licensePlate_ << "]";
            return os;  
        }    

    private:
        std::string owner_;
        std::string licensePlate_;
};


class Flyweight{
    public: 
    virtual ~Flyweight() {
        delete shared_state_;
    }

    Flyweight(const SharedState *shared_state) : shared_state_(new SharedState(*shared_state)){}
    Flyweight(const Flyweight &other) : shared_state_(new SharedState(*other.shared_state_)){}

    SharedState *shared_state() const{
        return shared_state_;
    }
    void Operation(const UniqueState &unique_state) const
    {
        std::cout << "Flyweight: Displaying shared (" << *shared_state_ << ") and unique (" << unique_state << ") state.\n";
    } 
    private: 
        SharedState *shared_state_;

};

class FlyweightFactory{
    public:

        FlyweightFactory(std::initializer_list<SharedState> share_states){
            for (const SharedState &ss : share_states){
                flyweights_.insert(std::make_pair(GetKey(ss), Flyweight(&ss)));
            }
        }

        Flyweight getFlyweight(const SharedState &shared_state){
            auto key = GetKey(shared_state);
            
            if (flyweights_.find(key) == flyweights_.end()){
                std::cout << "FlyweightFactory: Can't find a flyweight, creating new one.\n";
                flyweights_.insert(std::make_pair(key, Flyweight(&shared_state)));
            } else {
                std::cout << "FlyweightFactory: Reusing existing flyweight.\n";
            }
            return flyweights_.at(key);
        }

        void ListFlyweights() const{
          size_t count = this->flyweights_.size();
          std::cout << "\nFlyweightFactory: I have " << count << " flyweights:\n";
          for (std::pair<std::string, Flyweight> pair : flyweights_){
            std::cout << pair.first << "\n";
          }
        }
    private:
        std::unordered_map<std::string, Flyweight> flyweights_;
        std::string GetKey(const SharedState &ss) const {
            return ss.getKey();
        }
};

void addToDB(FlyweightFactory &ff, const std::string &owner, const std::string &licensePlate,
             const std::string &model, const std::string &color, const std::string &company){
    std::cout << "\nClient: Adding a car to database.\n";
    const Flyweight &flyweight = ff.getFlyweight(SharedState(model, color, company));
    // Client code either stores or uses the flyweight's instance
    flyweight.Operation(UniqueState(owner, licensePlate));  

}

int main(){
    FlyweightFactory *ff = new FlyweightFactory({
        {"BMW", "red", "M3"},
        {"Audi", "white", "A6"},
        {"Ford", "black", "Mustang"},
    });

    ff->ListFlyweights();

    addToDB(*ff, "John Doe", "CL234IR", "BMW", "red", "M3");
    addToDB(*ff, "James Doe", "CL234IR", "BMW", "red", "X1");
    addToDB(*ff, "Jake Doe", "CL234IR", "BMW", "black", "X3");

    ff->ListFlyweights();

    delete ff;
    return 0;
}