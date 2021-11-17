#include "boolean.h"

boolean new_game(char current[], int length){
    return(current[0] == 'i' && length == 1);
}

boolean load_game(char current[], int length){
    return(current[0] == 'i' && current[1] == 'i' && length == 2);
}

boolean exit_2(char current[], int length){
    return(current[0] == 'i' && current[1] == 'i' && current[2] == 'i' && length == 3);
}

boolean help(char current[], int length){
    return(current[0] == 'i' && current[1] == 'v' && length == 2);
}

boolean help_in(char current[], int length){
    return(current[0] == 'H' && current[1] == 'E' && current[2] == 'L' && current[3] == 'P' && length == 4);
}

boolean move(char current[], int length){
    return(current[0] == 'M' && current[1] == 'O' && current [2] == 'V' && current[3] == 'E' && length == 4);
}

boolean pick_up(char current[], int length){
    return(current[0] == 'P' && current[1] == 'I' && current [2] == 'C' && current [3] == 'K' && current[4] == '_' && current[5] == 'U' && current[6] == 'P' && length == 7);
}

boolean drop_off(char current[], int length){
    return(current[0] == 'D' && current[1] == 'R' && current [2] == 'O' && current [3] == 'P' && current[4] == '_' && current[5] == 'O' && current[6] == 'F' && current[7] == 'F' && length == 8);
}

boolean map(char current[], int length){
    return(current[0] == 'M' && current[1] == 'A' && current [2] == 'P' && length == 3);
}

boolean to_do(char current[], int length){
    return(current[0] == 'T' && current[1] == 'O' && current [2] == '_' && current[3] == 'D' && current[4] == 'O' && length == 5);
}

boolean in_progress(char current[], int length){
    return(current[0] == 'I' && current[1] == 'N' && current [2] == '_' && current [3] == 'P' && current[4] == 'R' && current[5] == 'O' && current[6] == 'G' && current[7] == 'R' && current[8] == 'E' && current[9] == 'S' && current[10] == 'S' && length == 11);
}

boolean buy(char current[], int length){
    return(current[0] == 'B' && current[1] == 'U' && current [2] == 'Y' && length == 3);
}

boolean inventory(char current[], int length){
    return(current[0] == 'I' && current[1] == 'N' && current [2] == 'V' && current [3] == 'E' && current[4] == 'N' && current[5] == 'T' && current[6] == 'O' && current[7] == 'R' && current[8] == 'Y' && length == 9);
}