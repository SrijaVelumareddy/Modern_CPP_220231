#include<iostream>
#include<optional>

//Factorial takes 1 int16_t by value and optionally returns a 
//size_t (sometimes, not always)
    //OR
//Factorial function MAY OR MAY NOT RETURN A VALUE
std::optional<size_t>Factorial(int16_t val){
    if(val<0){
        //throw std::invalid_argument("negative number\n");
        return std::nullopt; //a symbolic data value to indicate "NULL"
    }
    if(val==0 || val==1) {
        return 1;
    }

    else {
        size_t total {1};
        for(size_t i=2; i<=val; i++){
            total+=i;
        }
        return total;
    }
}
int main(){
    // try{
    //     Factorial(10);
    // }catch(std::invalid_argument& ex){
    //     std::cerr << ex.what() << "\n";
    // }
    //too complicated to use exceptions and flow is also disturbed

    

    //if(result.has_value()){

    if(std::optional<size_t> result=Factorial(-5); result.has_value()){
        std::cout << "Factorial is : " << result.value();
    } else {
        std::cerr << "factorial did not return a value\n";
    }

}

/*
    16 binary bits can generate a total of 2^16 == 65526

                -32768......0......32767
*/
/*
    define a function which takes a value

    if value is negative, I have nothing to return

    else if value is 0 or 1, I should return 1

    else {
        do a product of 2...value. Return the total
    }

    /////////////////

    main code is:
    
    call the function with a value. we get a "surprise" box!

    if surprise box has a value, print the value

    else{
        show a error message saying "I got nothing in the surprise box"
    }
*/