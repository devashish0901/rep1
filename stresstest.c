#include <stdio.h>
#include <stdlib.h>


    int main(int argc, char**argv){
        
        float a, i=0.000000001;
        float n= 0.00000001;
        int c = 1;

        for(i=0.0; a<n; a+=i){
            printf("Loop Number: %d\n", c);
            c++;
        }
        return 0;
    }