#include <stdio.h>
#include <string.h>

int main(){

    char name[25]; 
    int age;

    printf("\nWhats your name? ");
    fgets(name,25,stdin);
    //scanf("%s", name);
    name[strlen(name)-1] = '\0';

    printf("how old are you? ");
    scanf("%d", &age);
    printf("Hello, %s", name);
    printf(" you are %d years old\n", age);

    return 0;
}