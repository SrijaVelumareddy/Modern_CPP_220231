/*
    create an adaptor which accepts 
        a) a data container of string values
        b) a function with the following signature
            i) input parameter : one string by lvalue reference
            ii) output: void

        Adaptor should be used to perform operations on string values which are

        1) identify vowels
        2) print the last 3 characters of each string
        3) print the first non-vowel character of each string

*/

#include<iostream>
#include<functional>
#include<vector>

using Container = std::function< void (const std::string&)>;
using DataContainer = std::vector<std::string>;

void Adaptor(const Container fn,const DataContainer& data){
    if(data.empty()){
        std::invalid_argument("Data is empty");
    }
    for(const std::string& st : data){
        fn(st);
    }
}

void FindVowels(const std::string& val){
    if(val==""){
        std::cerr << "Cannot find vowels in an empty string\n";
        return;
    }

    bool atleastOneVowelFound{false};
    for( char c : val ) {
        if(c=='A' || c=='a' || c=='E' || c=='e' || c=='I' || c=='i' || c=='O' || c=='o' || c=='U' || c=='u') {
            atleastOneVowelFound=true;
            std::cout << c << "\n";
        }
    }
    if(!atleastOneVowelFound){
        std::cerr << "No vowels found\n";
    }
}

int main(){
    std::vector<std::string> data1{"","abc","xyz","mno"};
    std::vector<std::string> data2{"","","",""};
    std::vector<std::string> data3{};
    try{
        Adaptor(&FindVowels, data1);
        //Adaptor(&FindVowels, data2);
        //Adaptor(&FindVowels, data3);
    }catch(std::invalid_argument& ex){
        std::cerr<< ex.what() << "\n";
    }
    
    Adaptor( [](const std::string& st) { std::cout << st.length(); },data1); //this is not given in the question but in future if user wants to add few functions it is possible because this is functional programming 
    //for ex: the user wants to print the length of every string 
}

