#include <stdio.h>
#include <stdlib.h>


    int main(int argc, char**argv){
        
        float a, i=0.00000000000000001;
        float n= 0.0000000000000001;
        int c = 1;

        for(a=0.0; a<n; a+=i){
            printf("Loop Number: %d\n", c);
            c++;
        }
        return 0;
    }