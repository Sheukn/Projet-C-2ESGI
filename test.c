#include <stdio.h>

int main() {
    FILE *fp;
    char c;

    fp = fopen("map", "r"); // open the file for reading
    
    
    fclose(fp);
    
    return 0;
}