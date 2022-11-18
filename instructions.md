# Deliverables

- Classe Book
    - Variabili di membro
        - ISBN
        - Titolo: std::string, validazione: non vuoto
        - Nome e cognome dell'autore, con validazione: vuoto,in caso di mancanza unknown-unknown
        - Data di copyright: classe SetDate
        - Stato: bool
        - Funzioni per registrare il prestito e la restituzione
        - Overload degli operatori di confronto e output
        - Operatore << nel formato "titolo\n autore\n ISBN\n data_copyright"
        - getter e setter
- Classe Date (custom)
    - Sovrascrivere i vari operatori
    - Check di validità: per il mese, anno e giorno (non negativi e entro i limiti)
    - Optional: Implementare il check per il mese di febbrario (bisestile o no)
    - getter e setter
- Classe ISBN
    - Validazione del formato
    - Validazione della correttezza (checksum)
    - getter e setter

# Compiti

- Mouhieddine Sabir

    - Project setup
    - Creazione e management github repository
    - Creazione di test
    - Classe Book

- Alessandro Trigolo

    - Classe Date

- Antonio Tangaro

    - Classe ISBN

# Workflow

- Branch per ogni funzione principale, commit sul branch della tua funzione, pull request
- Non lavorare mai sul branch main/master
- Seguire Google C++ Style Guide

# Note
include: interfacce publiche
src: codice sorgenti
tests: 