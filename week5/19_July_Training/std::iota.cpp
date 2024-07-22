//find why this algorithm is called iota??


#include<iostream>
#include<vector>
#include<numeric>

/*
    v: {0,0,0,0,0}

    desired result: v: {19,20,21,22,23}
*/
int main(){
    std::vector<int> data{5}; //1 location with value 5
    //std::vector<int> data{1,2,3,4,5};
    std::vector<int> data(5); //correct construction with size 5
    //iota works on array, but not on vector correctly
    std::iota(
        data.begin(),
        data.end(),
        19
    );
}