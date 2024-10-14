#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** get_tests_string() {
    int size = 0;
    char** strings = (char**)malloc(sizeof(char*) * size);

    strings[0] = strdup("Cat");
    strings[1] = strdup("Mouse");
    strings[2] = strdup("Elephant");
    strings[3] = NULL; 

    return strings;
}

void print_strings(FILE* stream, char** string_array) {
     for (int i = 0; string_array[i] != NULL; i++) 
    {
        fprintf(stream, "%s\n", string_array[i]);
    }
}

char** load_lines(const char* filename) {
    
    FILE* file = fopen(filename, "r");

    int count = 1;
    char temp;

    while ((temp = fgetc(file)) != EOF) 
    {
        if (temp == '\n') 
        {
            count++;
        }
    }

    fseek(file, 0, SEEK_SET); 

    char** strings = malloc((count + 1) * sizeof(char*));

    int* lengths = (int*)malloc(sizeof(int)*count);

    for (int i = 0 ; i < count; i++)
    {
        int length = 0;
        while ((temp = fgetc(file)) != '\n' && temp != EOF) 
        {
            length++;
        }

        lengths[i] = length;
    }

    fseek(file, 0, SEEK_SET);

    for (int i = 0; i < count; i++) 
    {
        strings[i] = malloc(sizeof(char)*(lengths[i] + 1));
        if (!strings[i]) 
        {
            for (int k = 0; k < i; k++) 
            {
                free(strings[k]);
            }
            free(strings);
            free(lengths);
            fclose(file);
            return NULL;
        }

        fgets(strings[i], lengths[i] + 1, file);
    }

    strings[count] = NULL;

    free(lengths);
    fclose(file);
    return strings;

}

void destroy_strings(char*** p_string_array) {
    
    char** string_array = *p_string_array;

    for (int i = 0; string_array[i] != NULL ; i++)
    {
        free(string_array[i]);
    }

    free(string_array);
    *p_string_array = NULL;

}


int cmp(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void sort_strings(char** words) {
    int count = 0;
    while (words[count] != NULL) count++;
    qsort(words, count, sizeof(char*), cmp);
}


int main()
{
    char** strings_test = get_tests_string();
    print_strings(stdout , strings_test);



    return 0;
}