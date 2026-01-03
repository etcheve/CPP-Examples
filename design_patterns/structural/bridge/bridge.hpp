#pragma once
#include <memory>
#include "storage.hpp"


// Service uses different storage implementations via the Bridge pattern
class Service {
public:
    explicit Service(std::unique_ptr<Storage> storage)
        : storage_(std::move(storage)) {}

    virtual ~Service() = default;

protected:
    void store(const std::string& k,
               const std::string& v) {
        storage_->save(k, v);
    }

private:
    std::unique_ptr<Storage> storage_;
};


// une implementation of my Service
class UserService : public Service {
public:
    using Service::Service;

    void createUser(const std::string& id,
                    const std::string& name) {
        store(id, name);
    }
};

// another implementation of my Service
class OrderService : public Service {
public:
    using Service::Service;

    void createOrder(const std::string& id,
                     const std::string& product) {
        store(id, product);
    }
};
