#include <stdio.h> // Libreria standard input/output: serve per funzioni come printf e scanf
#include <math.h>  // Libreria matematica: serve per funzioni e costanti matematiche come M_PI
#define M_PI 3.14159265358979323846 //definizione manuale di π perchè mi dava errore anche con include <math.h>

//Questo programma legge un numero reale D che viene inserito dall'utente, 
// poi calcolerà e stamperò l'area di un quadrato, di un cerchio e di un triangolo equilatero

// int main() - Funzione principale da cui parte l'esecuzione del programma


int main() { 
    double D; // "double" viene usato per gestire numeri reali con decimali, D è la variabile che contiene il numero reale


    //Chiediamo all'utente di inserire un numero
    printf("Inserisci un numero: ");
    scanf("%lf", &D); // ''%lf'' specifica che si sta utilizzando un double ''&D'' indica dove salvare il numero


    // Calcoliamo l'area del quadrato con la formula ''area = lato * lato''
    double area_quadrato = D * D;
    printf("Area del quadrato: %.2lf\n", area_quadrato); //stampiamo il risultato


     // Calcoliamo l'area del cerchio con la formula ''area = π * raggio²''
    double r = D / 2; // Raggio = metà del diametro
    double area_cerchio = M_PI * r *r; 
    printf("Area del cerchio: %.2lf\n", area_cerchio);


    // Calcoliamo l'area del triangolo equilatero con la formula ''area = lato² * √3 / 4''
    double area_triangolo = ((D * D) * sqrt(3)) / 4;
    printf("Area del triangolo equilatero: %.2lf\n", area_triangolo);
 
    //Stampiamo i risultati
    printf("\n"); //stampa una riga vuota per separare i messaggi
    printf("Le aree calcolate sono:\n");

    printf("Area del quadrato: %.2lf\n", area_quadrato); // Stampa area quadrato
    printf("Area del cerchio: %.2lf\n", area_cerchio);   // Stampa area cerchio
    printf("Area del triangolo equilatero: %.2lf\n", area_triangolo); // Stampa area triangolo


    // Esercizio Facoltativo

    // Chiediamo all'utente di digitare 3 numeri
    
    double num1, num2, num3; //Creiamo tre variabili di tipo double, per salvare i tre numeri inseriti dall’utente
    printf("Inserisci 3 numeri, uno alla volta:\n");

    printf("Primo numero: ");
    scanf("%lf", &num1); // Legge un numero inserito dall’utente e lo salva dentro la variabile (num1 in questo caso)

    printf("Secondo numero: ");
    scanf("%lf", &num2);  

    printf("Terzo numero: ");
    scanf("%lf", &num3); 

    double somma = num1 + num2 + num3; // Somma dei 3 numeri inseriti dall'utente
    double media = somma / 3.0; //media dei 3 numeri

    printf("\nMedia (2 cifre decimali): %.2lf\n", media); // Stampa la media con 2 decimali
    int media_arrotondata = (int)(media + 0.5);   // Arrotonda il risultato
    printf("Media arrotondata: %d\n", media_arrotondata); //Stampa la media arrotondata

    
    // Calcolo delle aree delle 3 figure usando la media con decimali
    double areaQ_media = media * media;
    double areaC_media = M_PI * pow(media / 2, 2);
    double areaT_media = (pow(media, 2) * sqrt(3)) / 4;


    // Calcolo delle aree delle figure usando la media arrotondata
    double areaQ_arrotondata = media_arrotondata * media_arrotondata;
    double areaC_arrotondata = M_PI * pow(media_arrotondata / 2.0, 2);
    double areaT_arrotondata = (pow(media_arrotondata, 2) * sqrt(3)) / 4;


    // Stampa dei risultati
    printf("\n--- AREE usando la media con decimali ---\n");
    printf("Area del quadrato: %.2lf\n", areaQ_media);
    printf("Area del cerchio: %.2lf\n", areaC_media);
    printf("Area del triangolo equilatero: %.2lf\n", areaT_media);


    printf("\n--- AREE usando la media arrotondata ---\n");
    printf("Area del quadrato: %.2lf\n", areaQ_arrotondata);
    printf("Area del cerchio: %.2lf\n", areaC_arrotondata);
    printf("Area del triangolo equilatero: %.2lf\n", areaT_arrotondata);

 
    return 0; //indica che il programma è terminato correttamente



}

    