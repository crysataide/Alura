#include <stdio.h>

int main() {
    int nX;
    int num = 0;

    for (nX = 1 ; nX < 101 ; nX++) {
        num += nX;
    }
    printf("%d\n",num);
}