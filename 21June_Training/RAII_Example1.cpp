// RAII Resorce Acquisition Is Initialize

/*
    Resource:
        1) memory
        2) open files
        3) network connections
        4) 
*/

#include<iostream>

class ABC
{
private:
    int m_id {0};
    float* m_valuePtr{nullptr};
public:
    ABC() {}
    ABC(int id, float* ptr) : m_id{id},m_valuePtr{ptr}{}
    ABC(const ABC&)=delete;
    ABC(ABC&&)=delete;
    ABC& operator=(const ABC&)=delete;
    ABC& operator=(ABC&&)=delete;
    ~ABC() {
        delete m_valuePtr; //memory leakage prevented!!
    }
};

template <typename T>
class wrapper
{
private:
    T* m_ptr;

public:
    wrapper(T* ptr) : m_ptr {ptr} ()

    ~wrapper(){
        delete m_ptr;
    }
};

void Magic(){
    ABC* obj {new ABC{101, new float{200.0f}}};
    wrapper<ABC> wr_obj {obj};

    // or
    // wrapper<ABC> wr_obj {new ABC{101, new float{200.0f}}};
}

int main(){
    Magic();
    // ABC obj{101, new float{200.0f}};
    // ABC* obj {new ABC{101, new float{200.0f}}};
    // wrapper<ABC> wr_obj {obj};
}


/*
    main calls Magic()
    In magic function we create obj(stack memory)
    wr_obj stores the address of the heap allocated ABC object
    wr_obj will goes out of scope at the end of Magic function. Since we_obj is a stack allocated variable, it will get auto destructed. Destructor of Wrapper<ABC> class will be called.
    Wrapper class destructor will call delete on the stored pointer.
    For ABC  which will indirectly also delete it 

    memory...> box [memory will NEVER be SHARED] [ box is called shared_pointer]

    memory----> box [ memory will never be shared] [ box is called unique_pointer]

    memory---->box[Memory will "stalked"] {box is called weak_wrapper}

    function. callables --> box is called function_wrapper}

    references-->box {box is callec reference_wrapper}

    semaphores --> box {box is called 
        a) lock guard b) unique_lock ......
    }
    
*/