#include "displaymap.h"

int main() {
    Matrix m;

    // menggunakan config untuk driver displaymap
    char filename[WORD_CAPACITY + 1] = "config.txt";
    inputFilename(filename);

    if (loadConfig(filename, &newgame)) {
        readCustomMatrix(&m,newgame.mapRows+2,newgame.mapCols+2); // membuat matriks m dengan tambahan elemen border
        showMap(&m,newgame.bangunans); // meng-assign map list bangunan ke dalam matriks
        showRelation(m,newgame.bangunans,)
    }
}
