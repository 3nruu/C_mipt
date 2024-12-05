#include <iostream>
#include <string>
#include <cstdlib> 
#include <new>
using std::cout , std::endl;

template <typename T >

class Manager
{
private:

    T* mem;

public:

    Manager() 
    :   mem(nullptr) {}

    void allocate()
    {
        if (!mem)
        {
            mem = (T*)std::malloc(sizeof(T));
        }
    }

    void construct(const T& t)
    {
        new (mem) T(t);
    }

    void destruct()
    {
        if (mem)
        {
            mem->~T();
        }
    }

    void deallocate()
    {
        if (mem)
        {
            std::free(mem);
        }
    }

    T& get()
    {
        return *(this->mem);
    }
};


int main() {
    Manager<std::string> a;
    a.allocate();
    a.construct("Cats and dogs");
    a.get() += " and elephant";
    cout << a.get() << endl; // Должен напечатать Cats and dogs and elephant
    a.destruct();
    a.construct("Sapere Aude");
    cout << a.get() << endl; // Должен напечатать Sapere Aude
    a.destruct();
    a.deallocate();                   

    return 0;
}