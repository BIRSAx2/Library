### Una nota riguardo alle scelte progettuali effettuate

### Una nota riguardo alla naming convention utilizzata

Abbiamo deciso di seguire la Google C++ Code Style, con un piccolo cambiamento nella nomenclatura dei getter/setter
(chiamati accessors/mutators nella guida). Abbiamo utilizzato la stessa nomenclatura utilizzata per le funzioni
ordinarie ("Functions should start with a capital letter and have a  capital letter for each new word.") per essere 
più consistenti con la naming convention generale. Dopo aver consultato qualche progetto opensource in C++ di Google 
abbiamo verificato che questo è lo stesso approccio preso da loro nei progetto che abbiamo consultato.

# How to run

```bash
# Clonare questo repository
$ git clone https://github.com/BIRSAx2/library library
$ cd library
# Creare la directory build, se non esiste già
$ mkdir -p build
$ cd build

# Compilare ed lanciare l'eseguibile generato
$ cmake ../
$ cmake --build .
$ ./Library

```