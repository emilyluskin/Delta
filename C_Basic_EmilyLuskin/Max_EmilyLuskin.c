#include <stdio.h>
int main() {
    int x=5;
    int y=7;
    int z=(x>y)*x+(y>=x)*y;
    printf("Max value is %d\n", z);
    return 0;
}
