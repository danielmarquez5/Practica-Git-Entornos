#include <stdio.h>
#include <stdbool.h>

void Fibonacci(int *element, int n) {
    int anterior = 1, nou;
    *element = 1;
    while (n > 1) {
        n--;
        nou = anterior + *element;
        anterior = *element;
        *element = nou;
    }
}

bool realsiguals(float r1, float r2, float precisio) {
    float diff = r1 - r2;
    if (diff < 0.0) diff = -diff;
    return diff < precisio;
}

int main() {
    float precisio, rao_previa, rao;
    int e0, e1, e2, n = 2;
    printf("Introduce precision: ");
    scanf("%f", &precisio);
    Fibonacci(&e0, 0); Fibonacci(&e1, 1); Fibonacci(&e2, 2);
    rao_previa = (float)e1 / e0;
    rao = (float)e2 / e1;
    while (!realsiguals(rao, rao_previa, precisio)) {
        e0 = e1; e1 = e2; n++;
        Fibonacci(&e2, n);
        rao_previa = rao;
        rao = (float)e2 / e1;
    }
    printf("Rao auria: %.5f\n", rao);
    printf("Terme Fibonacci: %d\n", n);
    return 0;
}
