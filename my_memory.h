/* Author: Denice Veluz
Course: CSCI - 335
Assignment: Project 1
*/

#ifndef MY_MEMORY_HPP_  
#define MY_MEMORY_HPP_ 

#include <iostream>

template <class T>
class my_unique_ptr
{
    public:
        //Sets default constructor to point the object to nullptr
        my_unique_ptr();
        //The pointer Type (T*) will set the object to point to NewLocation
        my_unique_ptr(T* NewLocation);
        //The move constructor which will take the my_unique_ptr object and will create a new object from it
        my_unique_ptr(my_unique_ptr && rhs);
        //Copy constructor whihch will be disables/deleted explicitly
        //This deletes the function
        my_unique_ptr(const my_unique_ptr &rhs) = delete;
        //Destructor
        ~my_unique_ptr();
        //Dereference operator
        T& operator*();
        //Operator that will return the pointer to object
        T* operator->();
        //Move assignment operator
      my_unique_ptr& operator=(my_unique_ptr && rhs);
        //Copy assignment operator that will disable/delete explicity
        my_unique_ptr & operator=(const my_unique_ptr & rhs) = delete;
        //Returns true if pointer points to nullptr and false if it does not
        bool isNullptr();

    private:
        T* pointer;
};

template <class X>
class my_shared_ptr
{
    public:
        //Sets inner pointers to nullptr
        my_shared_ptr();
        /*
        //Constructor that will take Type (X*) and will set objct to point to NewLocation_Two
        //Will be the first my_shared_ptr so the counter will now be 1
        */
       my_shared_ptr(X* NewLocation_Two);
       //Copy constructor and now the newly created object will point there as well and it will increse counter by 1
       my_shared_ptr(const my_shared_ptr & rhs);
       //Move constructor
        my_shared_ptr(my_shared_ptr && rhs);
        //Destructor which will release/delete the block of memory and the counter if there are no other shared points there
        ~my_shared_ptr();
        //Dereference operator which will return the reference to the item that the object is pointing at 
        X& operator*();
        //Operator that will return the pointer to object
        X* operator->();
        /* //Copy assignment operator; if object pointing to somewhere, then counter decreases by 1
        //(if it reaches 0 then it should be deleted)
        //But increases the counter for the newly pointed block of memory
        */
        my_shared_ptr & operator=(const my_shared_ptr & rhs);
        //Move assignment operator
        my_shared_ptr & operator=(my_shared_ptr && rhs);
        //Returns true if pointer points to nullptr and false if it does not
        bool isNullptr();

 

    private:
        X* pointer_two;
        int* intcounter;
    
};

#include "my_memory.cpp"
#endif