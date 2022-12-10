#include <stdio.h>
#include <stdlib.h>

void free3LevelPtr(void ***ptr, ) {}

int main() {
    char ***res, quantity = 10;
    res = (char ***)malloc(sizeof(char **) * quantity);
    char **tmp_ch;
    for (int i = 0; i < quantity; i++) {
        res[i] = (char **)malloc(sizeof(char *) * 7);
        if (res[i]) {
            for (int j = 0; j < 7; j++) {
                res[i][j] = (char *)calloc(sizeof(char) * 8, 0);
                if (!res[i][j])
                    break;
            }
        }
    }

    return 0;
}