#include <iostream>
#include <vector>
#include <string>


template <typename T, typename Z>
class Iterator {
    public: 
    typedef typename std::vector<T>::iterator iter_type;
    Iterator(Z *data) : data_(data){
            m_it_ = data_->m_data_.begin();
    }

    void first() {
        m_it_ = data_->m_data_.begin();
    }
    void next() {
        ++m_it_;
    }
    bool isDone() const {
        return m_it_ == data_->m_data_.end();
    }
    iter_type currentItem() const {
        return m_it_;
    }
    private:    
        Z* data_;
        iter_type m_it_;
};

template <typename T>
class Container {
    friend class Iterator<T, Container>;
    public:
        void add(const T &item){
            m_data_.push_back(item);
        }
        Iterator<T, Container>* createIterator(){
            return new Iterator<T, Container>(this);
        }
        private:   
            std::vector<T> m_data_;
};

class Data{
    public:
        Data(int value) : value_(value){}
        void setData(int value){
            value_ = value;
        }
        int getData() const {
            return value_;
        }
    private:
        int value_;
};



int main(){
    std::cout << "Iterator Pattern Example\n";
    Container<int> container;
    for (int i = 0; i < 10; ++i){
        container.add(i);
    }

    Iterator<int, Container<int>>* it = container.createIterator();
    for (it->first(); !it->isDone(); it->next()){
        std::cout << "Value: " << *(it->currentItem()) << "\n";
    }

    Container<Data> cont2;
    Data a(100), b(1000), c(10000);
    cont2.add(a);
    cont2.add(b);
    cont2.add(c);
    Iterator<Data, Container<Data>> *it2 = cont2.createIterator();
    for (it2->first(); !it2->isDone(); it2->next()) {
        std::cout << it2->currentItem()->getData() << std::endl;
    }
    delete it;
    delete it2;
    return 0;
}