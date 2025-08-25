# Questo programma genera password personalizzate
# l'utente può scegliere tra password semplice o complessa
# password semplice: 8 caratteri alfanumerici
# password complessa: 20 caratteri con lettere maiuscole, minuscole, simboli e numeri


import string # importa il modulo "string" per ottenere lettere, numeri e simboli
import random # importa il moduno "random" per scegliere caratteri casuali


ALFANUMERICI = string.ascii_lowercase + string.ascii_uppercase + string.digits # charset che contine lettere minuscole, maiuscole e numeri.
TUTTI_ASCII = ALFANUMERICI + string.punctuation # charset che contiene lettere, numeri, simboli e punteggiatura



# stampiamo un messaggio di benvenuto per l'utente
print("Welcome! Let's create a strong password before the hackers find your cat pics!")

# chiediamo all'utente di scegliere che tipo di password vuole creare (semplice o complessa)
choice = input("Do you want a simple or complex password? (S/C): ")   # "input" legge la risposta dell'utente e la salva dentro al variabile "choice"

if choice.lower() == "s":    # if verifica la prima condizione (l'utente ha scelto password semplice) ed esegue il blocco 
    print("Simple password: 8 characters, letters and numbers only.")  # messaggio di istruzione per l'utente

elif choice.lower() == "c":  # verifica una secondo condizione solo se la prima è falsa
    print("Complex password: 20 character, must include uppercase, lowercase, numbers and symbols.")

else:                        # se nessuna delle condizioni precedenti è soddisfatta, mostra all'utente un messaggio d'errore
    print("Invalide choice! Try again")


# definiamo una funzione che prenderà la lunghezza della password scelta dall'utente (length)
# e l'insieme di carattere da cui scegliere (charset) 
# poi la password verrà generata

def generate_password(length: int, charset: str) -> str:

    password = [] # creiamo una lista vuota dove verranno inseriti i caratteri scelti dall'utente

    for i in range(length): # loop che esegue le istruzioni, "i" è una variabile che cambia valore ad ogni iterazione del ciclo
                            # range(length) genera una sequenza di numeri da 0 a length -1 (perche si parte sempre da 0)     
        letter = random.choice(charset) # prende un carattere random del charset

        password.append(letter) #aggiunge il carattere scelto alla listra "password"

    return ''.join(password)  # trasforma la lista in una stringa e la restituisce
                              # ' ' è una stringa vuota, fa si che i caratteri vengano uniti senza spazi
                              # .join() metodo per unire diverse stringhe in un'unica stringa 


# se la scelta è valida, la password viene generata e mostrata all'utente 

if choice.lower() == "s":
    password = generate_password(8, ALFANUMERICI) # password semolice
    print("Your password is: ", password)
    print("Keep it safe, do not tatoo it on your chest!")

elif choice.lower() == "c":
     password = generate_password(20, TUTTI_ASCII) # password complessa
     print("Your password is: ", password)
     print("Keep it safe, do not tatoo it on your chest!")


