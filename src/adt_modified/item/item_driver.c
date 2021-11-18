#include <stdio.h>
#include "../../game_header.h"

int main() {
    Item p, n, h;
    //item perish
    CreateItem(&p, 20, 'B', 'G', 'P', 10);
    //item normal
    CreateItem(&n, 20, 'F', 'B', 'N', 10);
    //item hheavy
    CreateItem(&h, 20, 'E', 'S', 'H', 10);

    // print item perish
    printf("Untuk item p");

    return 0;
}