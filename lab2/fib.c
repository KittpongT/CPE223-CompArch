#include <stdio.h>
int fib(int count)
{
    //condition of base case, the 1st and 2nd order of fibonucci is 1
    if (count == 0 || count == 1)
    {
        return 1;
    }

    //use recursion technique to find the sub sequence of this fibonucci which fib(n) is constructed fron fib(n-1) + fib(n-2)
    return fib(count - 1) + fib(count - 2);
}

int main()
{
    //declare the fibonucci order number which is 44
    int n = 44;

    //call print function to display the value while entering n into fib function
    printf("%d ", fib(n));
}