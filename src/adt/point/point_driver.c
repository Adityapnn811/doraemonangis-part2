#include <stdio.h>
#include "point.h"

int main() {
    POINT p;
    MakePOINT(3, 5);
    TulisPOINT(p);
    BacaPOINT(&p);
    TulisPOINT(&p);
    return 0;
}