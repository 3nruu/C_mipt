#include <stdio.h>

int main()
{
    printf("char: %lu\n", sizeof(char));
    printf("short: %lu\n", sizeof(short));
    printf("int: %lu\n", sizeof(int));
    printf("long long: %lu\n", sizeof(long long));
    printf("size_t: %lu\n", sizeof(size_t));
    printf("float: %lu\n", sizeof(float));
    printf("double: %lu\n", sizeof(double));
    printf("int[10]: %lu\n", sizeof(int[10]));
    printf("char[10]: %lu\n", sizeof(char[10]));

    return 0;
}
