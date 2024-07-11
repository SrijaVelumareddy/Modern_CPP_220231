/*
    n1 is non-const int by value
    lvalue will be copied, rvalues are assigned. Both are accepted.
    n1 shall not remain const in demo function (so can be modified)
    main value is remained same but copied value will be modified.
*/
void demo(int n1){

}

/*
    n1 is non-const lvalue reference to an integer
    lvalues can be accepted as a reference (no copy, no address received)
    n1 can be modified but it will modify original data passed

    example 1: int n1 {10}; demo{n1};
*/
void demo(int& n1){

}

/*
    n1 is const int by value
    lvalue will be copied, rvalues are assigned. Both are accepted.
    n1 shall remain const in demo function (so cannot be modified)
*/
void demo(const int n1){

}

/*
    n1 is a const lvalue reference to an integer
    lvalues and rvalues are both accepted.

    lvalues will be referred, rvalues will be assigned to n1
    either way, n1 cannot be modified inside demo function
*/
void demo(const int& n1){

}

/*
    n1 is non-const rvalue reference to an integer
    only rvalues are accepted, rvalue will be assigned to n1
    n1 can be modified in demo()
*/
void demo(int&& n1){

}

/*
    n1 is constant rvalue reference to an integer
    only rvalues are accepted, rvalue will be assigned to n1
    n1 cannot be modified in demo()
*/
void demo(const int&& n1){

}

/*
    n1 is a pointer to an integer
    an rvalue or lvalue address must be provided here
    n1 can change pointer it is holding. n1 can also modify data at the given location
    main:
    int value{10};
    demo(&value);

    demo
    -----
    int* n1=&value;

*/
void demo(int* n1){

}

/*
    n1 is a pointer to constant integer
    n1 can change the location it points to but data at the location shall remain non-modifyable
*/
void demo(const int* n1){

}

/*
    n1 is a constant integer to a non-const integer
    n1 can modify the data at the location is holds. But n1 cannot be reassigned to a different memory location
*/
void demo( int* const n1){

}

/*
    n1 is a const pointer to a const integer
    n1 cannot be reassigned,data cannot be modified using n1 either
*/
void demo(const int* const n1){

}

