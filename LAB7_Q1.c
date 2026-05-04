#include <stdio.h>

int hashFunction(int sapid) {
    int lastThree = sapid % 1000;
    return lastThree % 10;
}

int main() {
    int sapid;

    printf("Enter Student SAP ID: ");
    scanf("%d", &sapid);

    printf("Student belongs to Family %d\n", hashFunction(sapid));

    return 0;
}
