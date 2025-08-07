# Questo programma calcola perimetro e area di tre figure geometriche (quadrato, cerchio, rettangolo)
# L'utente inserisce un valore iniziale e sceglie le figure una alla volta
# L'area calcolata viene usata come nuovo valore per il calcolo successivo
# L’utente sceglie le figure da una lista che si aggiorna ad ogni passaggio, fino a esaurimento delle opzioni.

import math # Importa il modulo math per usare funzioni matematiche come pi greco


scelte_possibili = [1, 2, 3,] # Elenco delle figure che l'utente può scegliere

ok = False
while not ok:  # Esegue il blocco di codice finché la condizione è vera
    try:       # Prova ad eseguire il blocco di codice, se c'è errore passa a except
        valore = float(input("Inserisci il valore iniziale: ")) # Chiede un valore all'utente c
                                                                # Usiamo float per gestire anche valori con la virgola nei calcoli successivi
        ok = True
    except ValueError:  # gestisce cosa fare se c'è un errore nel blocco ''try'' senza bloccare il programma
        print("Devi inserire un numero!") # Stampa il messaggio


def scelta_utente(scelte_possibili: list[int]) -> int: # Mostra le figure disponibili e chiede all'utente di sceglierne una valida
    print("Scegli una figura tra quelle disponibili") 

    if 1 in scelte_possibili: 
        print("\t1) Quadrato")  

    if 2 in scelte_possibili: 
        print("\t2) Cerchio")    

    if 3 in scelte_possibili: 
        print("\t3) Rettangolo")        

        ok = False
        while not ok:  
            try:
                opzione = int(input("Inserisci il numero della figura: "))  # Converte l'input in intero e verifica se è tra le scelte valide
                if opzione in scelte_possibili:
                    ok = True
                else:                   # Gestisce il caso in cui l'utente scelglie un'opzione non presente nella lista
                    print(f"Scelta ({opzione}) non valida, riprova.")
            except ValueError:          # Se l'input non è un numero intero valido, mostra un messaggio di errore e chiede di nuovo 
                print("Devi inserire un numero intero!")

        return opzione                  # Ritorna la scelta valida 
    

# Il ciclo ''while'' continua finché ci sono figure disponibili da scegliere    
    
while len(scelte_possibili) > 0: 
    opzione = scelta_utente(scelte_possibili)  # Chiede all’utente di scegliere una figura disponibile
    scelte_possibili.remove(opzione)           # Togliamo la figura scelta per non proporla di nuovo

    if opzione == 1:       # Quadrato
        perimetro = valore * 4
        area = valore * valore
    elif opzione == 2:     # Cerchio
          perimetro = 2 * math.pi * valore
          area = math.pi * valore * valore
    elif opzione == 3:     # Rettangolo (lato corto = metà lato lungo)
          perimetro = valore * 3 
          area = valore * valore / 2
    else:
        raise Exception("Opzione non valida, impossibile!")
    
    print(f"Perimetro: {perimetro:.2f}") # ''.2f'' serve per mostrare i numeri con due cifre dopo la virgola
    print(f"Area: {area:.2f}")

    valore = area          # Aggiorniamo il valore iniziale con l’area calcolata per il prossimo ciclo

    
