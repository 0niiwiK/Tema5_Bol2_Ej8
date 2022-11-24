#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define JASIG 5
#define IALUM 10


void rellenaMatrizAleatorio(int m[][JASIG]);
void imprimeMatriz(int m[][JASIG]);
float mediaAlumno(int m[][JASIG],int alumno);
int mediaMaxima(int m[][JASIG]);
void examenMasAprobado(int m[][JASIG]);
void notaMaxima(int m[][JASIG]);

int main() {
    int notas[IALUM][JASIG];
    rellenaMatrizAleatorio(notas);
    imprimeMatriz(notas);
    int alumno_media_max= mediaMaxima(notas);
    printf("\nLa media mas alta es la del alumno %d que es %.2f", alumno_media_max+1, mediaAlumno(notas,alumno_media_max));
    examenMasAprobado(notas);
    notaMaxima(notas);
    return 0;
}

void rellenaMatrizAleatorio(int m[][JASIG]){
    srand(time(NULL));
    for (int i = 0; i < IALUM; ++i) {
        for (int j = 0; j < JASIG; ++j) {
            m[i][j]=rand()%10;
        }
    }
}

void imprimeMatriz(int m[][JASIG]){
    printf("\n-----------| Ex1 | Ex2 | Ex3 | Ex4 | Ex5 |\n");
    for (int i = 0; i < IALUM; ++i) {
        printf("Alumno %2d: |",i+1);
        for (int j = 0; j < JASIG; ++j) {
            printf("%3d  |",m[i][j]);
        }
        printf("\n");
    }
}

void examenMasAprobado(int m[][JASIG]){
    int aprobados, aprobados_max=0;
    int examen_mas_aprobado=0;
    for (int i = 0; i < JASIG; ++i) {
        aprobados=0;
        for (int j = 0; j < IALUM; ++j) {
            if (m[j][i]>=5)
                aprobados++;
        }
        if (aprobados>aprobados_max){
            aprobados_max=aprobados;
            examen_mas_aprobado=i;
        }
    }
    printf("\n\nEl examen que mas alumnos han aprobado es el examen %d que lo aprobaron %d\n",examen_mas_aprobado+1,aprobados_max);
}

float mediaAlumno(int m[][JASIG],int alumno){
    float media=0;
    for (int i = 0; i < JASIG; ++i) {
        media+=(float)m[alumno][i];
    }
    return media/JASIG;
}

int mediaMaxima(int m[][JASIG]){
    int max=0;
    float media;
    for (int i = 0; i < IALUM; ++i) {
        if (mediaAlumno(m,i)> mediaAlumno(m,max))
            max=i;
    }
    return max;
}

void notaMaxima(int m[][JASIG]){
    int maxima=0, alumno_max=0;
    for (int i = 0; i < JASIG; ++i) {
        maxima=0,alumno_max=0;
        for (int j = 0; j < IALUM; ++j) {
            if (m[j][i]>maxima){
                maxima=m[j][i];
                alumno_max=j;
            }
        }
        printf("\nLa nota maxima del examen %d, que la ha sacado el alumno %d, ha sido: %d",i+1,alumno_max+1,maxima);
    }
    printf("\n");
}