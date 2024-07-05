#include<iostream>
#include<variant>
#include<list>

int main(){
    std::variant<int,std::string> vr{10};
    //datatype with angular brackets is a template
    //variant is a collection of possible types of object

    //vr={std::list<int>{1,2,3}};

}