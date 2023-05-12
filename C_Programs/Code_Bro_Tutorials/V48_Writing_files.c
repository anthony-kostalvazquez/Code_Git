#include <stdio.h>

int main()
{
   // "w" will overwrite a file and "a" will append to the file
   FILE *pF = fopen("test.6", "w");

   fprintf(pF, "This will be put into the file");

   fclose(pF);
   
   // DELETE A FILE
   /*
   if(remove("test.txt") == 0)
   {
      printf("That file was deleted successfully!");
   }
   else
   {
      printf("That file was NOT deleted!");
   }
   */
   return 0;
}