/* Author: Denice Veluz
Course: CSCI - 335
Assignment: Project 1
*/

#include "my_memory.h" 
#include <iostream>

template<class T>
my_unique_ptr<T>::my_unique_ptr()
{
    pointer = nullptr;
}

template<class T>
my_unique_ptr<T>::my_unique_ptr(T* NewLocation)
{
    pointer = NewLocation;
}

//The move constructor which will take the my_unique_ptr object and will create a new object from it
template<class T>
my_unique_ptr<T>::my_unique_ptr(my_unique_ptr && rhs) : pointer(rhs.pointer)
{
    rhs.pointer = nullptr;
}

template<class T>
my_unique_ptr<T>::~my_unique_ptr()
{
    delete pointer;
}

template<class T>
T& my_unique_ptr<T>::operator*()
{
    return *pointer;
}

template<class T>
T* my_unique_ptr<T>::operator->()
{
    return pointer;
}

//Move assignment operator
template<class T>
my_unique_ptr<T>& my_unique_ptr<T>:: operator=(my_unique_ptr && rhs)
{
    T* temp = pointer;
    pointer = rhs.pointer;
    rhs.pointer = nullptr;
    if(temp != nullptr)
    {
        delete temp;
    }

    return *this;
}

template<class T>
bool my_unique_ptr<T>::isNullptr()
{
    if (pointer == nullptr)
    {
        return true;
    }

    else
    {
        return false;
    }
    
}

/**
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *  Beginning of shared_ptr
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */





//Sets inner pointers to nullptr
template<class X>
my_shared_ptr<X>::my_shared_ptr()
{
    pointer_two = nullptr;
    intcounter = nullptr;
}

//Constructor that will take Type (X*) and will set objct to point to NewLocation_Two
//Will be the first my_shared_ptr so the counter will now be 1
template<class X>
my_shared_ptr<X>::my_shared_ptr(X* NewLocation_Two)
{
    pointer_two = NewLocation_Two;
    intcounter = new int{1};
}

//Copy constructor and now the newly created object will point there as well and it will increse counter by 1
template<class X>
my_shared_ptr<X>::my_shared_ptr(const my_shared_ptr & rhs) : pointer_two(rhs.pointer_two), intcounter( rhs.intcounter)
{
    if(pointer_two != nullptr && intcounter !=nullptr)
    {
        ++(*intcounter);
    }
}

//Move constructor
template<class X>
my_shared_ptr<X>::my_shared_ptr(my_shared_ptr && rhs) : pointer_two(rhs.pointer_two), intcounter (rhs.intcounter)
{
 
 rhs.pointer_two = nullptr;
 rhs.intcounter = nullptr;
}

//Destructor which will release/delete the block of memory and the counter if there are no other shared points there
template<class X>
my_shared_ptr<X>::~my_shared_ptr()
{
    if(pointer_two != nullptr && intcounter != nullptr)
    {
        --(*intcounter);
        if(*intcounter == 0)
        {
            
            delete intcounter;
            delete pointer_two;
        }
        intcounter = nullptr;
        pointer_two = nullptr;
    }

}


//Dereference operator which will return the reference to the item that the object is pointing at 
template<class X>
X& my_shared_ptr<X>::operator*()
{
    return *pointer_two;
}

//Operator that will return the pointer to object
template<class X>
X* my_shared_ptr<X>::operator->()
{
    return pointer_two;
}

/* //Copy assignment operator; if object pointing to somewhere, then counter decreases by 1
//(if it reaches 0 then it should be deleted)
//But increases the counter for the newly pointed block of memory
*/
template<class X>
my_shared_ptr<X>& my_shared_ptr<X>:: operator=(const my_shared_ptr & rhs)
{
   
    int* temp = intcounter;
    X* temp_two = pointer_two;  
    if(pointer_two != nullptr && intcounter != nullptr)
    {
        --(*intcounter); //Decreases because you are copying it to a different place        
        intcounter = nullptr;
        pointer_two = nullptr;

    } //Now the LHS is blank
    if(pointer_two == nullptr && intcounter == nullptr)
    {
        pointer_two = rhs.pointer_two; 
        intcounter = rhs.intcounter;
        if(pointer_two != nullptr && intcounter != nullptr)
        {
            ++(*intcounter);
        }
        
    }

  if(temp != nullptr && temp_two != nullptr)
  {
      if(*temp == 0)
      {
          delete temp;
          delete temp_two;
      }
  }
    return *this; //Pointer to current object that is being edited (LHS)

}

//Move assignment operator
template<class X>
my_shared_ptr<X>& my_shared_ptr<X>:: operator=(my_shared_ptr && rhs)
{
    int* temp = intcounter;
    X* temp_two = pointer_two;  
    if(pointer_two != nullptr && intcounter != nullptr) //If LHS is already pointing to something
    {
        --(*intcounter); //Decreases because you are copying it to a different place        
        intcounter = nullptr; 
        pointer_two = nullptr; 
    }

    if(pointer_two == nullptr && intcounter == nullptr)
    {
        pointer_two = rhs.pointer_two;
        rhs.pointer_two = nullptr;

        intcounter = rhs.intcounter;
        rhs.intcounter  = nullptr;

    }

     if(temp != nullptr && temp_two != nullptr)
  {
      if(*temp == 0)
      {
          delete temp;
          delete temp_two;
      }
  }

    
    return *this;
}

 //Returns true if pointer points to nullptr and false if it does not
template<class X>
bool my_shared_ptr<X>::isNullptr()
{
     if (pointer_two == nullptr)
    {
        return true;
    }

    else
    {
        return false;
    }
}
