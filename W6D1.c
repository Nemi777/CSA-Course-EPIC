// Questo programma è quiz a scelta multipla a tema ''Harry Potter''
// L'utente può iniziare una nuova partita, scegliere la propria casa di Hogwarts e rispondere a tre domande.
// Le risposte corrette assegnano punti alla casata scelta.
// Alla fine viene mostrato il punteggio totale e un messaggio finale.


#include <stdio.h> //serve per usare le funzioni di input/output standard ( printf(), scanf(), etc.)
#include <string.h> // serve per funzioni che lavorano sulle stringhe (es. confrontare i nomi delle case di Hogwarts)
#include <stdbool.h> //serve per usare il tipo ''booleano'' (true/false)
#include <ctype.h> // contiene funzioni per lavorare con i caratteri (es. tolower() che non l'avevo inclusa)


// Definisco la funzione chooseHouse() prima di main() 
// perché il compilatore deve conoscere una funzione prima che venga chiamata
// quindi cosi facendo si evitano possibili errori quando la funzione vine usata nel main()


const char* choosehouse() {    // Funzione che restituisce una stringa constante (nome della casata scelta dall'utente)
    int choice;   // Variabile per salvare il numero inserito dall'utente
    while (true) { // Ciclo infinito fino a quando l'utente non inserisce un numero valido
        printf("Choose your Hogwarts House: \n\n");

        printf("1) Gryffindor\n"); // Opzioni di scelta
        printf("2) Slytherin\n");
        printf("3) Ravenclaw\n");
        printf("4) Hufflepuff\n\n"); 

        printf("Enter the number of your choice: "); 
        scanf("%d", &choice); // Legge il numero inserito dall'utente


        switch (choice) { // Verifica quale casata è stata scelta
            case 1:
                return "Gryffindor";
            case 2:
                return "Slytherin";
            case 3:
                return "Ravenclaw";
            case 4:
                return "Hufflepuff";
            default:   // Se l'utente non inserisce una delle opzioni il programma stampa errore e ricomincia il ciclo
                printf("Invalid choice, please try again\n\n");

        }
    }
}


// Definisco la funzione playGame() prima di main() per lo stesso motivo di cho0sehouse()
// Questa funzione gestisce il quiz, le domande, il punteggio e i messaggi finali 
// in base alla casata scelta dall'utente

int playGame(const char* house) {
    int score = 0; //punteggio iniziale
    int answer;

    // Prima domanda
    printf("Question 1: What's the name of Harry Potter's pet owl?\n\n");
    printf("1) Scabbers\n2) Crookshanks\n3) Hedwig\n\n");
    printf("Your answer: ");
    scanf("%d", &answer);

    if (answer == 3) {
        printf("Well done! 10 Points to %s!\n\n", house);
        score += 10;
    } else {
        printf("Wrong! You filthy little mudblood!\n\n");
    }
    
    // Seconda domanda
    printf("Question 2: What's the name of the dark forest near Hogwarts?\n\n");
    printf("1) Forbidden Forest\n2) Mirkwood\n3) Shadow Grove\n\n");
    printf("Your answer: ");
    scanf("%d", &answer);

    if (answer == 1) {
        printf("Well done! 10 Points to %s!\n\n", house);
        score += 10;
    } else {
        printf("Wrong! You filthy little mudblood!\n\n");
    }

    // Terza domanda
    printf("Question 3: Which sport is played at Hogwarts?\n\n");
    printf("1) Snorfblatting\n2) Quidditch\n3) Wombleskate\n\n");
    printf("Your answer: ");
    scanf("%d", &answer);

    if (answer == 2) {
        printf("Well done! 10 Points to %s!\n\n", house);
        score += 10;
    } else {
        printf("Wrong! You filthy little mudblood!\n\n");
    }

    return score; // da il punteggio totale
}


int main() {

    printf("Welcome to Harry Potter Trivia Quiz!\n\n"); //messaggio di benvenuto all'utente
    printf("Answer the questions and earn points for your House\n\n");

    char choice;  //variabile che contiene la scelta dell'utente

    while (true) {

        //ciclo infinito per mostrare il menu finche l'utente esce dal gioco
        printf("A) New Game\n");
        printf("B) Exit Game\n\n");
        printf("Your choice: \n\n");


        scanf(" %c", &choice);     // legge un carattere dall'input ignorando eventuali spazi vuoti

        switch(tolower(choice)) {  //converte in minuscolo per evitare problemi tra minuscole e maiuscole

            case 'a': {            // Se l'utente scenglie ''A'' inizia una nuova partita
                printf("Starting a new game..\n\n");
                const char* house = choosehouse(); // Chiediamo all'utente di scegliere la casata
                printf("\nYour house is: %s\n\n", house); // Confermiamo all'utente la casata scelta
                
                int score = playGame(house); // Avvia il quiz e salva il punteggio
                printf("Well done! Total points: %d\n\n", score);
                break;
            }

            case 'b': // Se l'utente sceglie ''B'' esce dal gioco
                printf("Exiting the game.. Goodbye!\n");
                return 0;

            default: // Se l'utente inserisce una scelta non presente, appare il messaggio e si ripete il ciclo
                printf("Invalid choice, please try again\n\n");
                break;
            
        }

    }  
    
    return 0; //termine del programma

}  



// Caro Valerio, spero tu sia fan di Harry Potter e che abbia risposto correttamente a tutte le domande.. in caso contrario, il gioco ti ha gia bullizzato abbastanza! :D <3