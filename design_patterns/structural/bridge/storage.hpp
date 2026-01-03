// storage.hpp
#pragma once
#include <string>
#include <iostream> 

class Storage {
public:
    virtual ~Storage() = default;
    virtual void save(const std::string& key,
                      const std::string& value) = 0;
};



class PostgresStorage : public Storage {
public:
    void save(const std::string& key,
              const std::string& value) override {
        std::cout << "[Postgres] " << key << " = " << value << '\n';
    }
};

class RedisStorage : public Storage {
public:
    void save(const std::string& key,
              const std::string& value) override {
        std::cout << "[Redis] " << key << " = " << value << '\n';
    }
};