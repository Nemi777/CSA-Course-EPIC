# Versione compatta dello stesso programma
# in aggiunta ho ordinato le parole in ordine alfabetico 
# e dalla piu corta alla piu lunga (perche mi annoiavo)


def lotr_precious(A: list[str]) -> list[int]:
    return [len(nome_personaggio) for nome_personaggio in A] # Restituisce la lista B con la lunghezza di ogni nome nella lista A, 
                                                             #calcolata tramite un "loop for" implicito nella list comprehension


A  = ["Frodo", "Samvise", "Gandalf", "Aragorn", "Gimli", "Legolas", "Gollum", "Galadriel", "Saruman", "Luthien"]

B = lotr_precious(A) 

print(A)
print()
print(B)


alfabetico_ascendente = sorted(A, key=lambda x: (len(x), x)) # sorted() restituisce una lista ordinata secondo paramentri che decidiamo
                                                             # key è il parametro, in questo caso una funzione lambda
                                                             # lambda è una funzione anonima che prende ogni elemento (x) della lista A 
                                                             # e crea una tupla (sequenza immutabile di valori ordinati) con 2 elementi, lunghezza della parola e parola stessa
                                                             # python prima ordina per lunghezza, se una o piu parole hanno la stessa lunghezza
                                                             # verranno ordinate alfabeticamente di defaul

print(alfabetico_ascendente)                                 # mostra tutte le parole ordinate prima per lunghezza e poi alfabeticamente