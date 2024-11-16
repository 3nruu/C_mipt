#include <stdio.h>

void set_characters(const char* begin, const char* end, char c)
{
    for(char* p = (char*)begin; p < end;p++)
    {
        *p = c;
    }
}


int main()
{
    char s[] = "Sapere Aude";
    set_characters(&s[2], &s[8], 'b');
    printf("%s\n", s); // Напечатает Sabbbbbbude
    set_characters(s, &s[4], 'a');
    printf("%s\n", s); // Напечатает aaaabbbbude
}