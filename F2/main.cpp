// Code for polymorphism
// Find and fix the 6 simple errors
// comment each line that was fixed

// When completed, upload good code and screen prints of successful execution.

// 1st one?
//#include "stdafx.h"
#include <iostream>
using namespace std;

//Create BASE class
class polygon{
protected:
    int width, height;
public:
    void set_values(int inW, int inH){
        width=inW; height=inH;
    }
        virtual int getArea(){
            return (0); 
            // error 5 needs virtual
    }    
};

//Create DERIVED class
class rectangle : public polygon{
public:
    int getArea(){return width*height;}
};

//Create DERIVED class
class triangle : public polygon {
public:
    // error 4 int getArea(){return width*height*1/42;}
    int getArea(){return width*height*1/2;}
};

//Create Poly function
void polyFun(polygon * ptrBase){
    
    //REPEAT code by using function
    //Key feature - base class pointer as argument..
    // error 3 cout << ptrBase.getArea() << endl; 
    
    cout << ptrBase->getArea() << endl;

}

int main()
{
    //Regular static declarations
    rectangle rect; 
    triangle trg1;
    //Regular use with dot notation
    cout << "-----------" << endl;
    rect.set_values(3, 4);
    cout << " Area of rectangle is: " << rect.getArea() << endl;
    trg1.set_values(3, 5);
    // error 2 cout >> " Area of triangle is: " << trg1.getArea() << endl;
    cout << " Area of triangle is: " << trg1.getArea() << endl;

    //......................................

    //WHY ... use ptr..?? FOR Polymorphism...
    rectangle * ptrRect= NULL; //Be absolutely clear that it has NO address
    triangle * ptrTrg1 = NULL;
    polygon * ptrPoly = NULL;

    ptrRect = &rect; //assign address to ptr variables
    ptrTrg1 = &trg1;

    //Polymorphism - ONE set of code that can work for MANY derived class.
    //key idea is - Declare ONE base class pointer... and assign ANY Derived class address to it

    // method 2 - GOOD REAL GOOD Method
    // make a function - so I only type code ONCE
    cout << "-----------" << endl;
    cout << " Area of triangle is: "; polyFun(ptrRect);//error 
    cout << " Area of rectangle is: "; polyFun(ptrTrg1);//error
    cout << "-----------" << endl;

    // error  not on windows system("pause");
    return 0;
}

