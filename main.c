#include <stdio.h>
#include <stdlib.h>

void citire_matrice(int ***matrice, int *n);
void verificare_elemente(int **matrice, int n);
void suma_elemente(int **matrice, int n);
void verificare_null(int **matrice, int n);
void scriere_matrice(int **matrice, int n);
void afisareMatrice(int **matrice, int n);

int main() {
    int **matrice;
    int n;

    // Citirea matricei
    citire_matrice(&matrice, &n);

    // Afișarea matricei inițiale
    printf("Matricea citita:\n");
    afisareMatrice(matrice, n);

    // Verificarea elementelor matricei
    verificare_elemente(matrice, n);

    // Calculul și afișarea sumei elementelor de pe penultima coloană
    suma_elemente(matrice, n);

    // Verificarea și afișarea mesajului pentru coloane nule
    verificare_null(matrice, n);

    // Înlocuirea elementelor de pe diagonala secundară cu '*'
    for (int i = 0; i < n; i++) {
        matrice[i][n - i - 1] = '*';
    }

    // Scrierea matricei în fișierul de ieșire
    scriere_matrice(matrice, n);

    // Eliberarea memoriei alocate dinamic
    for (int i = 0; i < n; i++) {
        free(matrice[i]);
    }
    free(matrice);

    return 0;
}

void citire_matrice(int ***matrice, int *n) {
    FILE *fp;
    char nume_fisier[] = "matrice.txt";
    fp = fopen(nume_fisier, "r");

    // Verificare dacă fișierul a fost deschis cu succes
    if (fp == NULL) {
        printf("Eroare la deschiderea fisierului!");
        exit(1);
    }

    // Citire dimensiune matrice
    fscanf(fp, "%d", n);

    // Alocare dinamică memorie pentru matrice
    *matrice = (int **)malloc(*n * sizeof(int *));
    for (int i = 0; i < *n; i++) {
        (*matrice)[i] = (int *)malloc(*n * sizeof(int));
    }

    // Citirea și verificarea elementelor matricei din fișier
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            int val;
            fscanf(fp, "%d", &val);
            // Verificare dacă valoarea este între 65 și 90 sau este 0
            if ((val >= 65 && val <= 90) || val == 0) {
                (*matrice)[i][j] = val;
            } else {
                printf("Elementul [%d][%d] nu respecta conditiile si va fi inlocuit cu 0.\n", i + 1, j + 1);
                (*matrice)[i][j] = 0;
            }
        }
    }

    // Închidere fișier de citire
    fclose(fp);
}

void verificare_elemente(int **matrice, int n) {
    // Adaugă aici codul pentru verificarea elementelor matricei
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = matrice[i][j];
            if (val < 65 && val != 0 || val > 90) {
                printf("Elementul [%d][%d] = %d este mai mic decat 65 sau mai mare decat 90 si diferit de 0.\n", i + 1, j + 1, val);
            }
        }
    }
}

void suma_elemente(int **matrice, int n) {
    // Calculul și afișarea sumei elementelor de pe penultima coloană
    int sumaPenultimaColoana = 0;
    for (int i = 0; i < n; i++) {
        sumaPenultimaColoana += matrice[i][n - 2];
    }
    printf("Suma elementelor de pe penultima coloana este: %d\n", sumaPenultimaColoana);
}

void verificare_null(int **matrice, int n) {
    // Verificarea și afișarea mesajului pentru coloane nule
    for (int j = 0; j < n; j++) {
        int coloanaNula = 1;
        for (int i = 0; i < n; i++) {
            if (matrice[i][j] != 0) {
                coloanaNula = 0;
                break;
            }
        }
        if (coloanaNula) {
            printf("Coloana %d este nula.\n", j + 1);
        }
    }

    // Verificarea și afișarea mesajului pentru linii nule
    for (int i = 0; i < n; i++) {
        int linieNula = 1;
        for (int j = 0; j < n; j++) {
            if (matrice[i][j] != 0) {
                linieNula = 0;
                break;
            }
        }
        if (linieNula) {
            printf("Linia %d este nula.\n", i + 1);
        }
    }
}

void scriere_matrice(int **matrice, int n) {
    FILE *fp;
    fp = fopen("output.txt", "w+");

    // Verificare dacă fișierul a fost deschis cu succes
    if (fp == NULL) {
        printf("Eroare la deschiderea fisierului de scriere!");
        exit(1);
    }

    // Scrierea matricei în fișierul de ieșire
    fprintf(fp, "%d\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(fp, "%c ", matrice[i][j] == '*' ? '*' : (matrice[i][j] == 0 ? '0' : matrice[i][j] + '0'));
        }
        fprintf(fp, "\n");
    }

    // Închidere fișier de scriere
    fclose(fp);
}


void afisareMatrice(int **matrice, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

