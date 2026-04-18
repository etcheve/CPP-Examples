#include <iostream>
#include <string>
#include <unordered_map>

struct SharedState {
    std::string model;
    std::string color;
    std::string company;

    std::string key() const { return model + "_" + color + "_" + company; }

    friend std::ostream& operator<<(std::ostream& os, const SharedState& s) {
        return os << "[Model: " << s.model << ", Color: " << s.color
                  << ", Company: " << s.company << "]";
    }
};

struct UniqueState {
    std::string owner;
    std::string licensePlate;

    friend std::ostream& operator<<(std::ostream& os, const UniqueState& u) {
        return os << "[Owner: " << u.owner << ", Plate: " << u.licensePlate << "]";
    }
};

class Flyweight {
public:
    explicit Flyweight(SharedState shared) : shared_(std::move(shared)) {}

    void operation(const UniqueState& unique) const {
        std::cout << "Flyweight: shared=" << shared_ << " unique=" << unique << '\n';
    }

private:
    SharedState shared_;
};

class FlyweightFactory {
public:
    explicit FlyweightFactory(std::initializer_list<SharedState> states) {
        for (const auto& s : states)
            pool_.emplace(s.key(), Flyweight(s));
    }

    const Flyweight& get(const SharedState& s) {
        auto key = s.key();
        auto it = pool_.find(key);
        if (it == pool_.end()) {
            std::cout << "FlyweightFactory: creating new flyweight\n";
            it = pool_.emplace(key, Flyweight(s)).first;
        } else {
            std::cout << "FlyweightFactory: reusing existing flyweight\n";
        }
        return it->second;
    }

    void list() const {
        std::cout << "\nFlyweightFactory: " << pool_.size() << " flyweights cached:\n";
        for (const auto& entry : pool_)
            std::cout << "  " << entry.first << '\n';
    }

private:
    std::unordered_map<std::string, Flyweight> pool_;
};

static void addToDB(FlyweightFactory& ff, const std::string& owner,
                    const std::string& plate, SharedState shared) {
    std::cout << "\nClient: adding car to database\n";
    ff.get(shared).operation({owner, plate});
}

int main() {
    FlyweightFactory ff({
        {"M3",      "red",   "BMW"},
        {"A6",      "white", "Audi"},
        {"Mustang", "black", "Ford"},
    });

    ff.list();

    addToDB(ff, "John Doe",  "CL234IR", {"M3",  "red",   "BMW"});
    addToDB(ff, "James Doe", "CL234IR", {"X1",  "red",   "BMW"});
    addToDB(ff, "Jake Doe",  "CL234IR", {"X3",  "black", "BMW"});

    ff.list();
}
