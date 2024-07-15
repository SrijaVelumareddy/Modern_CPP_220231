/*
    Reverse a string with no library functions with the help of a stack
*/
#include<iostream>
#include<optional>
#include<stack>

std::optional<std::string> StackReverseString(std::string& data){
    std::stack<char> reversed_characters{};

    for(const char c: data){
        reversed_characters.push(c);
    }

    std::string result {};

    while(!reversed_characters.empty()){
        result+=reversed_characters.top();
        reversed_characters.pop();
    }

    if(result.empty()){
        return result;
    }
}

int main(){
    
}