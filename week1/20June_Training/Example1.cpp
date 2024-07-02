#include <iostream>

class ABC
{
private:
    int m_id{0};
    float* m_valuePtr{nullptr};
public:

    ABC (int id,float* ptr) : m_id{id}, m_valuePtr{ptr} {}
    ABC()=default;
    ABC(const ABC&) = delete;
    ABC(ABC&&) = delete;
    ABC& operator=(const ABC&) = delete;
    ABC& operator=(ABC&&)=delete;
    ~ABC() {
        delete m_valuePtr;//memory leakage prevented!
    }
};

int main(){
    ABC obj {101,new float(200.0f)};
}