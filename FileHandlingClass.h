/* Controlla e gestire l'apertura del file e la gestione di eventuali errori che possono essere riscontrati
   Deve essere richiamata quando l'utente decide di aprire i file dai quali ottenere le informazioni da elaborare
   Per ognuno dei tre file esiste una classe propria con metodi propri di ogni classe insieme ad altri di cui è stato
   eseguito un override rispetto alla classe principale, in cui questi stessi metodi sono dichiarati virtuali o virtuali
   astratti. Il funzionamento è simile per ognuna delle tre classi figlie ed è il seguente:
  -Viene controllato il nome del file, la presenza del file e se il file è o meno vuoto;
  -Se i precedenti controlli sono favorevoli, viene controllata la formattazione di ogni file, in maniera diversa
   a seconda del tipo di file (es. se ci sono righe con solo testo o solo numeri oppure vuote);
   -Se anche la formattazione del file dà esito favorevole, vengono controllate le singole righe, anche questa volta
   in relazione alla formattazione, e se il controllo è favorevole, vengono creati degli oggetti riga per ogni classe
   (ogni classe è una classe file, al cui interno vi sono degli oggetti riga);
   -Infine se anche i controlli sui singoli campi danno riscontro favorevole, vengono creati gli oggetti
   delle classi presenti nel file "UtenteGenerico.h" e gli oggetti vengono memorizzati in delle vector diverse per ogni
   tipo di oggetto
*/


#ifndef DATAFILEHANDLE_FILEHANDLINGCLASS_H
#define DATAFILEHANDLE_FILEHANDLINGCLASS_H

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include "UtenteGenerico.h"


class FileHandlingClass {
public:

    FileHandlingClass() = default;
    ~FileHandlingClass() = default ;


    //Controlla il nome del file, l'apertura del file e se il file è o meno vuoto
    int aperturaFile();
    //Controlla se ci sono righe duplicate, oppure vuote o non coerenti col file(p.e. sono numeriche, solo alfabetiche) tramite trovaRigheErrate
    virtual int formattazioneFileControl() = 0;
    //Controlla se per ogni riga passata, essa è vuota, con sole lettere, soli numeri, sola punteggiatura,solo alfanumerica
    int trovaRigheErrate(const std::string &riga_da_input);
    //converte ogni singolo campo di ogni singola stringa in un dato da inserire in una variabile
    virtual int separaCampiFile() = 0;
    //Controlla se il nome del file ha caratteri errati
    int checkFilenameCorrectness()const;

protected:
    std::vector <std::string> container_righe_;
    std::string nome_file_;
    std::string singola_riga_;
    std::ifstream infile_;

};


class FileDbClass:public FileHandlingClass{
public:
    FileDbClass(const std::string &filename_);




    int separaCampiFile()override ;
    int formattazioneFileControl() override;


    //controlla la riga di un utente semplice, crea un oggetto utente semplice e ne salva il contenuto nella vector utente_s_
    void setUtenteSemplice(std::string utente_input_,const std::string &campo_id_,const std::string &campo_tipo_);
    //controlla la riga di un utente gruppo, crea un oggetto utente semplice e ne salva il contenuto nella vector utente_g_
    void setUtenteGruppo(std::string utente_input_,const std::string &campo_id_,const std::string &campo_tipo_);
    //controlla la riga di un utente azienda, crea un oggetto utente semplice e ne salva il contenuto nella vector utente_a_
    void setUtenteAzienda(std::string utente_input_,const std::string &campo_id_,const std::string &campo_tipo_);



    //permette di accedere alla vector in cui sono contenuti tutti gli oggetti utente semplice
    std::vector<UtenteSemplice> getUtente() const ;
    //permette di accedere alla vector in cui sono contenuti tutti gli oggetti utente gruppo
    std::vector<UtenteGruppo> getGruppo() const;
    //permette di accedere alla vector in cui sono contenuti tutti gli oggetti utente azienda
    std::vector<UtenteAzienda> getAzienda() const;

private:


    std::vector <UtenteSemplice> utente_s_;
    std::vector <UtenteGruppo> utente_g_;
    std::vector <UtenteAzienda> utente_a_;
};



class RelationshipsClass:public FileHandlingClass{
public:
    RelationshipsClass(const std::string &filename_);
    //separa e controlla i campi di ogni singola riga del file delle relazioni, crea gli oggetti relativi al file e li salva nella vector container_relazioni_
    int separaCampiFile()override ;
    //Controlla se ci sono righe duplicate, oppure vuote o non coerenti col file(p.e. sono numeriche, solo alfabetiche) tramite trovaRigheErrate
    int formattazioneFileControl() override;

    //permette di accedere alla vector in cui sono contenuti tutti gli oggetti relazioni
    std::vector<Relazioni> getContainerRelazioni()const;

private:
    Relazioni rel_obj_;
    std::vector<Relazioni> container_relazioni_;
};

class SetofNewsClass:public FileHandlingClass{
public:
    SetofNewsClass(const std::string &filename_);


    //separa e controlla i campi di ogni singola riga del file delle news, crea gli oggetti relativi al file e li salva nella vector container_news_
    int separaCampiFile()override ;
    //Controlla se ci sono righe duplicate, oppure vuote o non coerenti col file(p.e. sono numeriche, solo alfabetiche) tramite trovaRigheErrate
    int formattazioneFileControl() override;
    //Controlla se i campi dislike e like hanno degli id coerenti col contenuto del file
    int controllaCorrettezzaid( std::string stringa_id_);

    //permette di accedere alla vector in cui sono contenuti tutti gli oggetti news
    std::vector<NewsClass> getContainerNews()const;


private:
    std::vector<NewsClass> container_news_;
};




#endif //DATAFILEHANDLE_FILEHANDLINGCLASS_H