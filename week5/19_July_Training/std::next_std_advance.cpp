#include<iostream>
#include<list>
 
int main(){
    //objective : move iterators on containers which don't support ramdom access without manually writing for loops
 
    std::list<int> data {1,2,3,4,5};
 
    auto itr = data.begin();
 
    auto new_itr = std::next(itr,data.size()-3);
 
    std::advance(itr, data.size()-3); //itr will be modified to new position, no new variable created
 
 
    //next will give whole new itr , advance will modify the same itr;
}