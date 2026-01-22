#include <stdio.h>
#include "shoto.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprint(stderr, "shoto: what are you focusing on?\n");
        return 1;
    }

    printf("Not implemented yet. But you said: %\n", argv[1]);
    return 0;
}
