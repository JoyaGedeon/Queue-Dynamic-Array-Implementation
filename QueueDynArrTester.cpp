/******************************************************************************* 
 * File:   QueueDynArrTester.cpp
 * Author: Joya Gedeon.
 *
 ********************************* QueueDynArrTester.cpp ***********************
 * The tester class show the manipulation of queues.
 * 
 * Operations are:
 *      displayMenu: Displays the available methods to be used on the queue.
 *      userChoice: Show the result of the user's choice number from the menu.
 *      main: Declaration of the queue and its manipulation.
 * 
 * Created on November 29, 2021, 8:15 PM
 ******************************************************************************/ 
#include <iostream>
#include <string>
#include "QueueDynArr.h"
using namespace std;

/** DisplayMenu.
     * Display menu to the user.
     * 
     * Precondition: None.
     * Post-condition: Menu is displayed.
     */
void displayMenu(){
    cout << "\n|---------------------------------------|"
         << "\n|                Menu                   |"
         << "\n|---------------------------------------|"
         << "\n 1) Check if Queue is empty."
         << "\n 2) Check if Queue is full." 
         << "\n 3) Insert a specific value to the queue."
         << "\n 4) Remove the front element."
         << "\n 5) Get the front element of the queue."
         << "\n 6) Display queue elements."
         << "\n 0) Exit.";
}

/** userChoice.
     * Execute menu method according to user choice.
     * 
     * Precondition: None.
     * Post-condition: Chosen method by user is executed.
     */
template <typename ElementType> 
void userChoice(int choice, QueueDynArr <ElementType> & queue){
    // Variable Value is declared in case user chooses to enqueue a value.
    ElementType value;
    // Cases of user's choice from the menu.
    switch(choice){
        // Case 0: Exit.
        case 0:
            break;
        // Case 1: isEmpty.
        case 1:
            cout << ((queue.isEmpty()) ?"\n>*Queue Is Empty*" 
                    : "\n> *Queue Isn't Empty*");
            cout << "\n-----------------------\n"
                 << "\n> *Queue List:* <" << endl;
            cout << queue;
            cout << "-----------------------\n";
            break;
        // Case 2: isFull.
        case 2:
            cout << ((queue.isFull()) ? "\n>>*Queue Is Full*" 
                    : "\n>>*Queue Isn't Full*");
            cout << "\n-----------------------\n"
                 << "\n> *Queue List:* <" << endl;
            cout << queue;
            cout << "-----------------------\n";
            break;
        // Case 3: enqueue.    
        case 3:
            cout << "\n>>>Enter value desired to be added: \n";
            cin  >> value;  
            queue.enqueue(value);
            cout << "\n-----------------------\n"
                 << ">>>Value has been added.\n"
                 << "\n> *Queue List:* <" << endl;
            cout << queue;
            cout << "-----------------------\n";
            break;
        // Case 4: dequeue.      
        case 4:
            queue.dequeue();
            cout << "\n>>>>The front value has been removed"
                 << "\n-----------------------\n"
                 << "\n> *Queue List:* <" <<endl;
            cout << queue;
            cout << "-----------------------\n";
            break;
        // Case 5: front.      
        case 5:
            cout << "\nFor reference:"
                 << "\n> *Queue List:* <" <<endl;
            cout << queue;
            cout << "\n>>>>>>The front value of the queue is:" << queue.front();
            cout << "\n-----------------------\n";
            break;
        // Case 6: display (queue).      
        case 6:
            cout << "\n> *Queue List:* <"
                 << "\n-----------------------\n";
            cout << queue;
            cout << "-----------------------\n";
            break;        
    }
}

/** main
     * 
     * 
     * Precondition: None.
     * Post-condition: Manipulation of queues.
     */
int main(){
    int choice,     // Choice: user choice from the menu.
        capacity;   // capacity: capacity of the queue.
    
    cout << "What is the capacity you wish to set on the queue: ";
    cin  >> capacity;   // input capacity.
    cout << endl; 
    
    //Declaration of queue with capacity as parameter.
    QueueDynArr <int> queue(capacity);
    
    /**
     * >>>
     * To try all the data types,
     * Remove comment format from wanted queue type. (And comment previous type)
     */
        //    QueueDynArr <float> queue(capacity);
        //    QueueDynArr <double> queue(capacity);
        //    QueueDynArr <char> queue(capacity);
        //    QueueDynArr <string> queue(capacity);
    
    // Loop while user do not choose 0
    do{
        // Display the menu.
        displayMenu();
        cout << "\n---------------------------------------\n"; 
        cout << "Please choose a number from the menu: ";
        cout << "\n---------------------------------------\n"; 
        // User choice of number from menu.
        cin >> choice;
        cout << endl;
        // Choice number is in-range
        if( choice > 0 && choice < 7){
            userChoice(choice, queue);
            cout << endl;
        }
        // Choice number is out-of-range 
        // 0 is used for Exit
        else if(choice < 0 || choice > 6){
            cout << "Wrong Choice of Number!!" << endl;
        }
    }while(choice!= 0); 
    // User selects to exit
    // End
    return 0;
}
