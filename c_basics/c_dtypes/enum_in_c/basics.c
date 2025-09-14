#include <stdio.h>


// * refer notes

enum enum_name {
    value1,
    value2,
    value3,
};


enum Days { MON, TUE, WED, THU, FRI, SAT, SUN }; // vith default value

enum Status { SUCCESS = 1, FAILURE = -1, PENDING = 0 }; // with our own value

enum TrafficLight { RED, YELLOW, GREEN };


int main(void){
    enum Days today = WED; // ! here WED is a const from the enum Days (maybe we can also define by value)
    enum Days yesterday = 5.0; // can also be assigned by the values (but takes any value so not useable and everthing is converted to int)
    printf("Today is day number: %d\n", today); // Output: 2
    printf("yesterday is day number: %d\n", yesterday); 

    enum TrafficLight signal = GREEN;

    switch (signal) {
        case RED:
            printf("Stop!\n");
            break;
        case YELLOW:
            printf("Get Ready!\n");
            break;
        case GREEN:
            printf("Go!\n");
            break;
    }
    return 0;
}