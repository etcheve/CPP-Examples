#pragma once
#include <iostream>
#include <list>

struct FileSystemObject {
    virtual ~FileSystemObject() = default;

    virtual void Add(std::unique_ptr<FileSystemObject> obj) = 0;
    virtual void Remove() = 0;
    virtual void Delete(FileSystemObject* obj) = 0;
    virtual void DisplayAll() const = 0;
    virtual bool operator==(const FileSystemObject &other) const {
        return this == &other;
    }
};



class File : public FileSystemObject {
public:
    explicit File(std::string name)
        : name_(std::move(name)) {}

    void Add(std::unique_ptr<FileSystemObject>) override {
        // A file cannot contain children — no-op or throw
        throw std::logic_error("Cannot add to file");
    }

    void Delete(FileSystemObject* /*obj*/) override {
        std::cout << "Deleting file: " << name_ << '\n';
    }

    void Remove() override {
        std::cout << "Removing file: " << name_ << '\n';
    }

    void DisplayAll() const override {
        std::cout << "File: " << name_ << '\n';
    }

private:
    std::string name_;
};


class Directory : public FileSystemObject {
public:
    explicit Directory(std::string name)
        : name_(std::move(name)) {}

    void Add(std::unique_ptr<FileSystemObject> obj) override {
        children_.push_back(std::move(obj));
        std::cout << "Adding to directory: " << name_ << '\n';
    }

    void Delete(FileSystemObject* obj) override {
        children_.remove_if([&](const std::unique_ptr<FileSystemObject>& p) {
            return p.get() == obj;
        });
    }

    void Remove() override {
        children_.clear();
    }

    void DisplayAll() const override {
        std::cout << "Directory: " << name_ << '\n';
        for (const auto& child : children_) {
            child->DisplayAll();
        }
    }

private:
    std::list<std::unique_ptr<FileSystemObject>> children_;
    std::string name_;
};
