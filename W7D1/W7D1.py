# Questo programma prende in input una lista A di parole (in questo caso nomi dei personaggi del Signore degli Anelli) 
# e crea una lista B con numeri corrispondenti alle cifre di ogni parola.



def lotr_precious(A: list[str]) -> list[int]: # definiamo la funzione LOTR_prescoius che, data la lista A (stringa di parole)
                                              # restituisce la lista B (che contiene numeri interi)
    B = []                                    # creiamo una lista vuolta dove andranno le lunghezze della parole                                          


    for nome_personaggio in A:            # "for" inizia un "loop" o ciclo, quindi ripete una serie di istruzioni piu volte, in questo caso, per ogni elemento della lista A

        lunghezza = len(nome_personaggio) # la funzione "len()" calcola il numero di caratteri delle parole

        B.append(lunghezza)               # aggiunge la lunghezza calcolata alla lista B

    return B                              #restituisce la lista completa delle lunghezze



# definiamo le variabili A (lista di input) e B (lista di stringe da elaborare)
A = ["Frodo", "Samvise", "Gandalf", "Aragorn", "Gimli", "Legolas", "Gollum", "Galadriel", "Saruman", "Luthien"]

B = lotr_precious(A) 

print("Lista delle parole: ", A)      # stampiamo la lista delle parole
print("")                             # stampa una stringa vuota che ho voluto aggiugere solo per estetica
print("Lunghezza delle parole: ", B)  # stampiamo la lunghezza 




