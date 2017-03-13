/* Lab notes from Lab4 */

/* 
 *
 */

class Human{

    const int gender_flag;
    const char c;

    Human(int i) : gender_flag(i),
                   c('a'){
            
        }

};

class Point2D{

    // data
    int x;
    int y;

public:
    // Constructor/Destructor
    Point2D(){}
    Point2D(int x, int y){  // overload
        this->x = x;
        this->y = y;
    }
    ~Point2D(){}
    // Functions
    void say_hello();

    // operator overloads
    Point2D& operator+ (Point2D other){

    }
};

#include <iostream>


int main(){

    Point2D p();

    std::istream& in  = std::cin;
    std::ostream& out = std::cout;


    return 0;
}

