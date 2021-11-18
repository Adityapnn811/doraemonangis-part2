#include "../../game_header.h"

int main() {
    Matrix m;
    // CreateMatrix(12,17,&m);

    // menggunakan config untuk driver displaymap
    char filename[WORD_CAPACITY + 1] = "config.txt";
    // inputFilename(filename);
    Config newgame;
    POINT p = MakePOINT(1,2);

    if (loadConfig(filename, &newgame)) {

    }
    readCustomMatrix(&m,newgame.mapRows+2,newgame.mapCols+2); // membuat matriks m dengan tambahan elemen border
    showMap(&m,newgame.bangunans); // meng-assign map list bangunan ke dalam matriks
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
    showRelation(newgame.adjMatrix,newgame.bangunans,p);
}
