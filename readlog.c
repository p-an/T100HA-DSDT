#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFSIZE 0x70

int main(int argc, char ** argv){
    char buf[BUFSIZE];
    FILE * fin;
    const char * fin_n = argv[1];
    if(!(fin = fopen(fin_n,"r"))){
        printf("Cannot open %s\n",fin_n);
        return 1;
    }

    while(fread(buf,BUFSIZE,1,fin)){
        int l = strnlen(buf,BUFSIZE);
        if(l > 0 && buf[l-1]=='\n')buf[l-1]=0;
        printf("%s\n",buf);
    }


    return 0;
}
