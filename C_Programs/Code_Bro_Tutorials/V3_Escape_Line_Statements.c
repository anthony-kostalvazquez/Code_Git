#include <stdio.h>
int main(){
    
    // This is a comment
    /*
        This
        is
        a
        multiline
        comment
    */
   
    /* escape sequence = character combination consisting of a backslash \ 
                         followed by a letter or combination of digits.
                         They specify actions within a line of text (string)
                         \n = newline
                         \t = tab 
                         \\ = display \
                         \' = display '
                         \" = display "
    */


   printf("I\nlike\npizza!\n");

   //Here i print a matrix using escape sequences
   printf("1\t2\t3\n");
   printf("4\t5\t6\n");
   printf("7\t8\t9\n");

    /* Here i print a \ */
    printf("\\ \n");

    //Here i print quotation marks
    printf("\' \n");
    printf("\"");

    return 0;
}