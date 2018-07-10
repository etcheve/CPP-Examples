#include<vector>
#include<iostream>

class A{

  public:

    A(){
      std::cout << "default Contructor call" << std::endl;
    }
    A(const A& a){
      std::cout << "Copy Contructor call" << std::endl;
    }
    ~A(){
      std::cout << "Descturctor call" << std::endl;
    }
};

int main()
{
  std::vector<A> v;
  A a;
  std::cout <<  "First Push"  << std::endl;
  v.push_back(a);

  std::cout << std::endl <<  "Second Push"  << std::endl;
  v.push_back(a);

  std::cout << std::endl <<  "Third Push"  << std::endl;
  v.push_back(a);

  std::cout << std::endl <<  "Fourth Push"  << std::endl;
  v.push_back(a);

  std::cout << std::endl <<  "Fifth Push"  << std::endl;
  v.push_back(a);

  std::cout << "Before shrink to fit: Vector's Size: "<<v.size() << " Vector's Capacity: "<< v.capacity() << std::endl;
  v.shrink_to_fit();
  std::cout << "After shrink to fit: Vector's Size: "<<v.size() << " Vector's Capacity: "<< v.capacity() << std::endl;

  std::cout << std::endl <<  "Second Test"  << std::endl;

  std::vector<A> c;
  c.reserve(5);
  c.push_back(a);
  c.push_back(a);
  c.push_back(a);
  c.push_back(a);
  c.push_back(a);
  std::cout << "Reserved Vector's Size: "<<v.size() << " Vector's Capacity: "<< v.capacity() << std::endl;
}
