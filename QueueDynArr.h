/******************************************************************************* 
 * File:   QueueDynArr.h
 * Author: Joya Gedeon.
 *
 ********************************* QueueDynArr.h *******************************
 * This header file defines the data type of a Queue object.
 * 
 * Operations are:
 *      Constructors: 
 *          QueueDynArrTester: no-arg constructor to declare an object Queue.
 *          QueueDynArrTester: arg-constructor creating empty Queue with a 
 *                             specified capacity.
 *          QueueDynArrTester: copy constructor copying a Queue object's data.
 *      Destructor: 
 *          ~QueueDynArrTester: Destructor, deletes dynamic data.
 *      Methods: 
 *          isEmpty: Checks if queue is empty.
 *          isFull: Checks if queue is full.
 *          enqueue: Insert value at the back of the queue.
 *          dequeue: Remove value at the front of the queue.
 *          front: return the front value of the queue.
 *          operator=: Make the leftHandSide object equal to the 
 *                     rightHandSide.
 *          display: Displays the queues values.
 * 
 * Created on November 29, 2021, 8:13 PM
 ******************************************************************************/ 

#ifndef QUEUEDYNARR_H
#define QUEUEDYNARR_H
#include <iostream>
using namespace std;

template <typename ElementType> 
class QueueDynArr{
public:
/**********************************Function Members****************************/
  /***Constructors***/
    /** No-Arg Constructor.
     * Construct a queue object.
     * 
     * Precondition: None.
     * Post-condition: An empty queue object has been constructed; myFront and
     *                 myBack is initialized to 0 and -1 respectively.
     */
    QueueDynArr();
    
    /** Arg Constructor.
     * Construct a queue object with capacity as a parameter.
     * 
     * Precondition: None.
     * Post-condition: An empty queue object has been constructed; myFront and
     *                 myBack is initialized to 0 and -1 respectively, capacity 
     *                 is set to the parameter value.
     */
    QueueDynArr(int);
    
    /** Copy Constructor
     *  Construct a copy queue object to the passed parameter original queue.
     * 
     * Precondition: None.
     * Post-condition: A (deep) copy of the original queue is instantiated.
     */
    QueueDynArr(const QueueDynArr&);
    
    /** Destructor
     *  Deletes all dynamic data of the queue object.
     * 
     * Precondition: None.
     * Post-condition: Queue is empty and deleted.
     */
    virtual ~QueueDynArr();
    
    /** isEmpty method
     *  Checks if queue is empty or not.
     * 
     * Precondition: None.
     * Post-condition: Return true if queue is empty, otherwise return false.
     */
    bool isEmpty() const;
    
    /** isFull method
     *  Checks if queue is full or not.
     * 
     * Precondition: None.
     * Post-condition: Return true if queue is full, otherwise return false.
     */
    bool isFull() const;
    
    /** enqueue method
     *  Inserts at the front of the queue a value.
     * 
     * Precondition: Parameter value should be of type ElementType.
     * Post-condition: Value has been added to the front of the queue.
     */
    void enqueue(ElementType v);
    
    /** dequeue method
     *  Deletes the back value of the queue
     * 
     * Precondition: None.
     * Post-condition: Back value has been deleted from the queue;
     */
    void dequeue();
    
     /** font method
     *  Returns the value at the front of the queue.
     * 
     * Precondition: The queue shouldn't be empty.
     * Post-condition: Returns the front value of the queue.
     */
    ElementType front() const;
    
     /** operator= method
     *  Makes the leftHandSide object equal to the rightHandSide.
     * 
     * Precondition: None.
     * Post-condition: The object on the left is now equal to the object to the
     *                the right of the operator.
     */
    QueueDynArr& operator = (const QueueDynArr&);
    
    /** display method
     *  Display the queue.
     * 
     * Precondition: None.
     * Post-condition: The values of the queue will be displayed.
     */
    void display();
    
/******************************************************************************/
   
private:
/**********************************Data Members********************************/
    int myCapacity;       // Array's capacity
    int myFront;          // Array's front index
    int myBack;           // Array's back index
    ElementType* myArray; // Dynamic array's pointer;
/******************************************************************************/  
};

/******************************** I/O Operators *******************************/
template <typename ElementType>
ostream& operator << (ostream&, QueueDynArr <ElementType> &);
template <typename ElementType>
istream& operator >> (istream&, QueueDynArr <ElementType> &);

#endif

//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

/**
 ******************************** QueueDynArr.cpp ******************************
 * 
 * This file implements Queue member functions.
 * 
*/
//-- No-Arg Constructor Definition
template <typename ElementType> 
QueueDynArr<ElementType>::QueueDynArr(){
    myArray = new (nothrow) ElementType[myCapacity]; // Pointer assigned
    if (myArray != 0) { // memory available
        myFront = 0;    // Default myFront value
        myBack = -1;    // Default myBack value
        myCapacity = 5; // Default myCapacity value
    } else {
        cerr << "NoArgCon: *Inadequate memory to allocate queue ***\\n"
                " -- terminating execution\n";
        exit(1);
    }
}

//-- Arg Constructor Definition
template <typename ElementType>
QueueDynArr<ElementType>::QueueDynArr(int myCapacity){
    myArray = new (nothrow) ElementType[myCapacity]; 
    if (myArray != 0) { // memory available
        myFront = 0;    // Default myFront value
        myBack = -1;    // Default myBack value
        this->myCapacity = myCapacity;  // Input myCapacity value
    } 
    else {
        cerr << "ArgCon_Error: *Inadequate memory to allocate queue \n"
                " -- terminating execution\n";
        exit(1);
    }
}

//-- Copy Constructor Definition
template <typename ElementType>
QueueDynArr<ElementType>::QueueDynArr(const QueueDynArr& original){
    // Copying original data members to this
    myFront = original.myFront;
    myBack = original.myBack;
    myCapacity = original.myCapacity;
    myArray == new (nothrow) ElementType[myCapacity]; // original.myFront?
    if (myArray != 0)
        // Copying myArray's value to this object's myArray.
        for(int i = 0; i <= myBack; i++){
            myArray[i] = original.myArray[i];
        }
    else {
        cerr << "CopyCon_Error:*Inadequate memory to allocate queue ***\n";
        exit(1);
    }
}

//-- Destructor Definition
template <typename ElementType>
QueueDynArr <ElementType>::~QueueDynArr(){
    delete [] myArray;
}

//-- isEmpty method Definition
template <typename ElementType>
bool QueueDynArr<ElementType>::isEmpty() const{
    return myBack == -1;
}

//-- isFull method Definition
template <typename ElementType>
bool QueueDynArr<ElementType>::isFull() const{
     return ((myBack + 1) % myCapacity == myFront) && (!isEmpty()); 
}

//-- enqueue method Definition
template <typename ElementType>
void QueueDynArr<ElementType>::enqueue(ElementType v){
    // Queue is empty // Enqueue the first element
    if(isEmpty()){
        myBack++;
        myArray[myBack] = v;
    } 
    // Queue is full // Add myCapacity
    if (isFull()){
        // capacity += 5;
        ElementType* temp = new(nothrow)ElementType [myCapacity + 5];
        for(int i = 0; i <= myBack; i++){
            temp[i] = myArray[i];
        }
        myCapacity += 5;
        delete myArray;
        myArray = temp;
    }
    // Queue full or not, enqueue at myBack.
    int newBack = (myBack + 1) % myCapacity;
    myArray[myBack] = v;
    myBack = newBack;
}


//-- dequeue method Definition
template <typename ElementType>
void QueueDynArr<ElementType>::dequeue(){
    // Queue is empty
    if(isEmpty()){
        cerr << "CopyCon_Error:*Inadequate memory to allocate queue ***\n";
        exit(1);
    }
    // Queue not empty
    else{
        // Dequeue myFront // Changing index of myFront
        myFront = (myFront + 1) % myCapacity;
    }
}

//-- font method Definition
template <typename ElementType>
ElementType QueueDynArr<ElementType>::front() const{
    // Checking if queue is empty
    if(isEmpty()){ 
        cerr << "Front_Error: ***Queue is empty***\n";
        exit(1);
    } else {
        return myArray[myFront]; //if not empty return myFront
    }
}

//-- operator= method Definition
template <typename ElementType>
QueueDynArr <ElementType>& QueueDynArr <ElementType> ::operator=
(const QueueDynArr &rightHandSide){
    // Both object are not equal
    if(this != &rightHandSide){
        // this capacity is not equal to the rightHandSide's capacity
        if(myCapacity != rightHandSide.myCapacity){
            delete [] myArray;
            myCapacity = rightHandSide.myCapacity;
            myArray = new ElementType[myCapacity];
            if(myArray == 0){
                 cerr << "Op=_Error:*** Inadequate memory ***\n";
                 exit(1);
            }  
        }
        // Assign this object data members to the rightHandSide members's data.
        myFront = rightHandSide.myFront;
        myBack  = rightHandSide.myBack;
        int i; 
        // Fill this object's array with the rightHandSide queue's values.
        for (i = 0; i <= myBack; i++)
            myArray[i] = rightHandSide.myArray[i];
    }
    return *this;
}

//-- display method Definition
template <typename ElementType>
void QueueDynArr<ElementType>::display(){
    // Queue is not empty
    if(!isEmpty()){
        int i;
        for(i = myFront; i != myBack; i = (i + 1)% myCapacity)
            cout << myArray[i] << ", ";
        cout << endl;
    }
    else{
        cerr << "Display_Error: ***Queue is empty***\n";
        exit(1);
    }
}

//-- operator << method Definition
template <typename ElementType>
ostream& operator << (ostream& output, QueueDynArr <ElementType>& queue){
    // Call of display method for object queue
     queue.display();
     return output;
      
}

//-- operator >> method Definition
template <typename ElementType>
istream& operator >> (istream& input, QueueDynArr <ElementType> & queue){
    // Data to be added to the queue
    ElementType value;
        cout  << "\nEnter the element of queue: ";
        input >> value;
        queue.enqueue(value);
        cout  << endl;
    return input;
}
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//

