#include <stdio.h>
#include "../../game_header.h"

int main() {
    POINT p = MakePOINT(3, 5);
    TulisPOINT(p);
    printf("\n");
    BacaPOINT(&p);
    TulisPOINT(p);
    return 0;
}