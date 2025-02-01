#include <stdio.h>

void update(int *a,int *b) {
	int aux;

	aux = *a + *b;
	*b = (*b - *a > 0 ? *b - *a : *a -*b);
	*a = aux;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
