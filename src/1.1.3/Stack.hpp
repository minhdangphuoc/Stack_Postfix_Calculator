#define __STDC_LIMIT_MACROS
#include <stdint.h>

typedef double Stack_entry;
//typedef char Stack_entry;
typedef enum Error_code{success, overflow, underflow} Ecode; //just add for pass the warning, dont need to add this.

const int maxstack = 100;

class Stack {
public:
    Stack( );
    bool empty( ) const;
    Error_code pop( );
    Error_code top(Stack_entry &item) const;
    Error_code push(const Stack_entry &item);
    friend Error_code copy_stack(Stack &dest, Stack &source);
private:
    int count;
    Stack_entry entry[maxstack];
};

