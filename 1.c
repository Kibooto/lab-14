#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float A, B, C, D;
} Plane;

void find_normal_vector(Plane p, float* n) {
    n[0] = p.A;
    n[1] = p.B;
    n[2] = p.C;
}

void input_plane(Plane* p) {
    printf("Введіть коефіцієнти A, B, C та D: ");
    scanf("%f %f %f %f", &p->A, &p->B, &p->C, &p->D);
}

int are_perpendicular(Plane p1, Plane p2) {
    float n1[3], n2[3];
    find_normal_vector(p1, n1);
    find_normal_vector(p2, n2);
    float dot_product = n1[0] * n2[0] + n1[1] * n2[1] + n1[2] * n2[2];
    return dot_product == 0;
}

int main() {
    Plane p1, p2, p3;

    printf("Ввід 1 вектора:\n");
    input_plane(&p1);

    printf("Ввід 2 вектора:\n");
    input_plane(&p2);

    printf("Ввід 3 вектора:\n");
    input_plane(&p3);

    printf("Чи є 1 та 2 вектори перпендикулярними %d\n", are_perpendicular(p1, p2));
    printf("Чи є 1 та 3 вектори перпендикулярними %d\n", are_perpendicular(p1, p3));
    printf("Чи є 2 та 3 вектори перпендикулярними %d\n", are_perpendicular(p2, p3));

    return 0;
}
