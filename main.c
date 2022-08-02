#include "stdio.h"

int main(int argc, char * argv[]) {
    char c;
    FILE* f = NULL;
    int escaping = 0;
    if (argc > 0) {
        f = fopen(argv[1], "w+");
    }
    while((c = getchar()) != EOF) {
        putchar(c);
        if(f) {
            if(escaping == 1) {
                if(c=='m' || c=='K') //probably a lot of other escape endings but I just care about color codes, and "Erase until EOL" for now
                    escaping = 0;
            } else {
                if (c != 27)
                    fputc(c, f);
                else
                    escaping = 1;
            }
        }
    }
    return 0;
}