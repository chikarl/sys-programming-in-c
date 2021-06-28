#include "../../apue.h"
#include <stdio.h>
// int fputc(int c, FILE *stream)

int main() {
    FILE *sfp, *dfp;
    char curr;
    
    
    sfp = fopen("open.txt", "r");
    if( sfp == NULL ) {
        printf("%s\n", strerror(errno)); exit(0);
    } else {
        dfp = fopen("dest.txt", "w");
        if ( dfp == NULL ) {
            printf("%s\n", strerror(errno));
        } else {
            while((curr = fgetc(sfp)) != EOF) {
                if(fputc(curr, dfp) == EOF) {
                    printf("%s\n", strerror(errno));
                }
            }
        }
        
    }
    
}