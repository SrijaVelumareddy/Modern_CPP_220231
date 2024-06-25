/*
    first class functions

    A language is said to treat "functions" as first-class if the following things are possible in the language

    a) functions have a properly recognize types.
    b) functions can be passed as parameters to the functions.
    c) functions can be returned as parameters from the functions (closures)
    d) functions can be addressed/copied into the other variables.
                                or
        functions can be 'saved' in a variable
    e) functions can be stored in a container

*/
 
 #include<iostream>
 #include<functional>
 #include<vector>

 void Magic(std::function<void(const int32_t)> fn){
    fn(10); //square of 10
 }
 //rule3 part 1
 std::function<void(int32_t)> Demo(){
    return [](const int32_t val) {return val * val * val * val;};
 }
 int main(){
    //Type of fn:
    /*
        a function which accepts one int32_t by value, returns void
    */
    auto fn = [](const int32_t val) { std::cout << val * val;};

    //rule2:
    Magic(fn); //works

    //rule3 part 2
    auto ans = Demo(); //accept the function returned in a variable

    //rule 4
    auto temp = ans; //'function' copied

    auto* ptr = &ans; //addressing also works

    //rule 5 : functions can be saved in other containers
    std::vector< std::function<void(int32_t)>  > fns{fn};
 }