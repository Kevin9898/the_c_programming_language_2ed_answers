#include <stdio.h>
enum e1 {
    ONE = 1,
    TWO,
    THREE= 2,
    FOUR = 3,
    FIVE = 3
};
float s1 = 1.0;
float s2 ;

main(int argc, char const *argv[])
{
    /* code */
    enum e1 a  = ONE;
    enum e1 b = FOUR;
    enum e1 c = FIVE;
    printf("b == c : %d!\n", b==c);
    return a;
}
