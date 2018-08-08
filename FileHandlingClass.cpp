#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cctype>
#include <iterator>
#include <algorithm>
#include "FileHandlingClass.h"
#include "UtenteGenerico.h"




//controlla se il nome file ha caratteri proibiti
//tramite un if controlla se nel nome_file_ questi caratteri sono presenti e se ci sono il return è -1, altrimenti -2
int FileHandlingClass::checkFilenameCorrectness()const{
    if (nome_file_.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_.") != std::string::npos)
    {
        return -1;
    }
    return -2;
}


/*
Richiama il metodo che si occupa di controllare la correttezza del nome (checkFilenameCorrectness), se il nome è corretto apre il file, se
l'apertura è avvenuta con successo controlla che il file non sia vuoto tramite il metodo peek() che ritorna il prossimo
carattere che verrà letto dal file, se esso è EOF, il file è vuoto. Se invece il file non è vuoto, il contenuto viene
inserito, riga per riga in una vector (ogni riga corrisponde a un campo della vector) e viene chiuso il file;
 */
int FileHandlingClass::aperturaFile() {

    std::string stringa_campo_;

    if(checkFilenameCorrectness() == -2){
        infile_.open(nome_file_);
        if(infile_.is_open()){
            if(infile_.peek() != EOF){
                while(getline(infile_,stringa_campo_,'\n')){
                    container_righe_.push_back(stringa_campo_);
                }
                infile_.close();
                return -1;
            }else{
                infile_.close();
                return -2;
            }
        }else{
            return -3;
        }
    }else{
        return -4;
    }
}



/*
Attraverso un ciclo for si entra nella vector in cui ci sono le righe del file, e ogni campo della vector viene salvato
in singola_riga_; si controlla che eliminando il contenuto di singola_riga_ fino al carattere '}', non
ci siano altri caratteri dopo quest'ultimo. Successivamente si controlla che non ci siano righe duplicate e infine,
attraverso il metodo "trovaRigheErrate", si controlla che in singola_riga ci sia una riga coerente con la formattazione del
file
 */

int FileDbClass::formattazioneFileControl(){

    for(int i = 0; i != container_righe_.size(); ++i){
        singola_riga_ = container_righe_[i];
        singola_riga_ = singola_riga_.erase(0,singola_riga_.find_first_of('}')+1);
        for(int j = i + 1; j != container_righe_.size(); ++j){
            if(container_righe_[i] == container_righe_[j]){
                std::cerr << "La riga numero "<< i + 1 << " contenente "  << container_righe_[i] << " è duplicata" << std::endl;
            }
        }if(trovaRigheErrate(container_righe_[i])  != 6){
            std::cerr << "La riga numero " << i + 1 << " contenente " << container_righe_[i] << " non è coerente col file" << std::endl;
        }else if(!singola_riga_.empty()){
            std::cerr << "La riga numero " << i + 1 << " contenente " << container_righe_[i] << " ha dei caratteri dopo le parentesi" << std::endl;
        }
    }
    return -1;
}

FileDbClass::FileDbClass(const std::string &filename_) {
    nome_file_ = filename_;
}

/*
Controlla che la riga passata dal metodo "formattazioneFileControl()" rispetti le seguenti proprietà:
-Che non sia una riga vuota;
-Che non sia una riga solamente numerica;
-Che non sia una riga solamente alfabetica;
-Che non sia una riga con sola punteggiatura;
-Che non sia una riga totalmente alfanumerica
tutto ciò viene portato a termine tramite l'algoritmo all_of(), il quale controlla che ogni carattere di ogni stringa
rispetti una determinata proprietà che viene stabilita come terzo parametro;
 */
int FileHandlingClass::trovaRigheErrate(const std::string &riga_da_input){
    if(riga_da_input.empty()){
        return 1;
    }else if(std::all_of(riga_da_input.begin(),riga_da_input.end(),isdigit)){
        return 2;
    }else if(std::all_of(riga_da_input.begin(),riga_da_input.end(),isalpha)){
        return 3;
    }else if(std::all_of(riga_da_input.begin(),riga_da_input.end(),ispunct)){
        return 4;
    }else if(std::all_of(riga_da_input.begin(),riga_da_input.end(),isalnum)){
        return 5;
    }else{
        return 6;
    }
}

/*
Attraverso un ciclo for si entra nella vector in cui ci sono le righe del file, e ogni campo della vector viene salvato
in singola_riga_; successivamente singola_riga_ viene 'spacchettata' nei campi: campo_id_, campo_tipo_ e
campo_utente_ tramite i metodi erase, e substr; Dopo ogni operazione di 'spacchettamento', di singola_riga_ viene
eliminata la parte relativa al campo appena creato fino ad ottenere alla fine del processo una stringa vuota.
Contemporaneamente, per il campo appena creato vengono effettuati dei controlli in relazione al tipo di campo, per
esempio: se è stato inizializzato il campo_id_, si controlla che il campo non sia vuoto o non alfanumerico e
successivamente si elimina da singola_riga_ la parte di stringa che corrisponde a campo_id;
 */
int FileDbClass::separaCampiFile() {
    std::string campo_id_;
    std::string campo_tipo_;
    std::string campo_utente_;


    for(int i = 0; i != container_righe_.size(); ++i) {
        singola_riga_ = container_righe_[i];
        campo_id_ = singola_riga_.substr(0, singola_riga_.find_first_of(','));
        if((!std::all_of(campo_id_.begin(), campo_id_.end(), isalnum)) || campo_id_.empty() || (std::all_of(campo_id_.begin(), campo_id_.end(), isdigit))) {
            std::cerr << "La riga numero " << i + 1 << " contenente " << container_righe_[i] << " è errata, -2" << std::endl;
            return -2;
        }else{
            singola_riga_ = singola_riga_.erase(0, singola_riga_.find_first_of(',') + 1);
            campo_tipo_ = singola_riga_.substr(0, singola_riga_.find_first_of(','));
            if(campo_tipo_ != "US" && campo_tipo_ != "UG" && campo_tipo_ != "UA"){
                std::cerr << "La riga numero " << i + 1 << " contenente " << container_righe_[i] << " è errata, -3" << std::endl;
                return -3;
            }else{
                singola_riga_ = singola_riga_.erase(0, singola_riga_.find_first_of(',') + 1);
                campo_utente_ = singola_riga_.substr(0,singola_riga_.find_first_of('}')+1);
                if(singola_riga_.empty()){
                    std::cerr << "La riga numero " << i + 1 << " contenente " << container_righe_[i] << " è errata -4" << std::endl;
                    return -4;
             }else{

                    if(campo_tipo_ == "US"){
                        setUtenteSemplice(campo_utente_,campo_id_,campo_tipo_);
                    } else if(campo_tipo_ == "UG") {
                        setUtenteGruppo(campo_utente_,campo_id_,campo_tipo_);
                    }else if(campo_tipo_ == "UA") {
                        setUtenteAzienda(campo_utente_,campo_id_,campo_tipo_);
                    }
                }
            }
        }
    }

    return -1;
}



/*La riga passata da separaCampiFile per l'oggetto utente semplice viene spacchettata nei campi che compongono utente semplice e la riga passata da input viene
 * di volta in volta ridotta della stessa parte che è stata salvata in singola_riga_. Sulla variabile singola_riga_ vengono effettuati dei controlli, se essa
 * è vuota o il campo non è ben definito, ovvero se manca l'identificativo del campo (p.e per il campo nome, questo è composto da Nome:nome. Se Nome: è mancante, viene
 * generato un errore). Successivamente si crea una sottostringa di singola_riga_ in cui si controlla solo il contenuto del campo dopo i due punti. Se esso è vuoto
 * o non è coerente con il tipo di dato che deve contenere, viene generato un errore, altrimenti il contenuto di singola_riga_ viene salvato nel campo corrispondente.
 * Solo alla fine di questo processo, applicato ad ogni campo, si procede a chiamare i metodi che permettono di inizializzare l'oggetto utente semplice e di salvarne
 * l'oggetto stesso in una vector di tipo utente semplice*/
void FileDbClass::setUtenteSemplice(std::string utente_input_,const std::string &campo_id_,const std::string &campo_tipo_) {
    std::string singola_riga_;
    std::string campo_nome_;
    std::string campo_cognome_;
    std::string campo_sesso_;

    UtenteSemplice *ptr_s = nullptr;


    singola_riga_ = utente_input_.substr(utente_input_.find_first_of('{') + 1, utente_input_.find_first_of(','));
    if (singola_riga_.empty() || singola_riga_.find("Nome:") == std::string::npos) {
        std::cerr << "In " << utente_input_ << " il campo nome non è definito correttamente" << std::endl;
    } else {
        singola_riga_ = singola_riga_.substr(singola_riga_.find_first_of(':') + 1, singola_riga_.find_first_of(','));
        singola_riga_.erase(singola_riga_.find_first_of(','));


        if (singola_riga_.empty()) {
            std::cerr << "In " << utente_input_ << " il campo nome è vuoto" << std::endl;
        } else {
            campo_nome_ = singola_riga_;
            utente_input_ = utente_input_.erase(0, utente_input_.find_first_of(',') + 1);
            singola_riga_ = utente_input_.substr(0, utente_input_.find_first_of(','));


            if (singola_riga_.empty() || singola_riga_.find("Cognome:") == std::string::npos) {
                std::cerr << "In " << utente_input_ << " il campo cognome non è definito correttamente" << std::endl;
            } else {
                singola_riga_ = singola_riga_.substr(singola_riga_.find_first_of(':') + 1);
                if (singola_riga_.empty()) {
                    std::cerr << "In " << utente_input_ << " il campo cognome è vuoto" << std::endl;
                } else {
                    campo_cognome_ = singola_riga_;
                    utente_input_ = utente_input_.erase(0, utente_input_.find_first_of(',') + 1);
                    singola_riga_ = utente_input_.substr(0, utente_input_.find_first_of(','));

                    if (singola_riga_.empty() || singola_riga_.find("Sesso:") == std::string::npos) {
                        std::cerr << "In " << utente_input_ << " il campo sesso non è definito correttamente" << std::endl;
                    }else{
                        singola_riga_ = singola_riga_.substr(singola_riga_.find_first_of(':') + 1);
                        if (singola_riga_.empty() || (singola_riga_ != "M" && singola_riga_ != "F")) {
                            std::cerr << "In " << utente_input_ << " il campo sesso è vuoto o non è definito correttamente" << std::endl;
                        }else{
                            campo_sesso_ = singola_riga_;
                            utente_input_ = utente_input_.erase(0, utente_input_.find_first_of(',') + 1);
                            singola_riga_ = utente_input_.substr(0, utente_input_.find_first_of(','));

                            if (utente_input_.empty() || utente_input_.find("Data_Di_Nascita:") == std::string::npos) {
                                std::cerr << "il campo data di nascita non è definito correttamente" << std::endl;
                            } else {
                                utente_input_ = utente_input_.substr(utente_input_.find_first_of(':') + 1, utente_input_.find_last_not_of('}'));
                                utente_input_ = utente_input_.erase(utente_input_.find_last_of('}'));
                                if (utente_input_.empty() || std::all_of(utente_input_.begin(), utente_input_.end(), isalpha)) {
                                    std::cerr << "il campo data di nascita è vuoto o non è definito correttamente" << std::endl;
                                } else {
                                    ptr_s = new UtenteSemplice();
                                    ptr_s->setId(campo_id_);
                                    ptr_s->setTipo(campo_tipo_);
                                    ptr_s->setNome(campo_nome_);
                                    ptr_s->setCognome(campo_cognome_);
                                    ptr_s->setSesso(campo_sesso_);
                                    ptr_s->setDataNascita(utente_input_);
                                    utente_s_.push_back(*ptr_s);
                                    delete ptr_s;

                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

/*Come utente semplice*/
void FileDbClass::setUtenteGruppo(std::string utente_input_,const std::string &campo_id_,const std::string &campo_tipo_) {
    std::string singola_riga_;
    std::string campo_nome_gruppo_;
    std::string campo_sede_legale_;
    std::string campo_tipo_att_;

    UtenteGruppo *ptr_g = nullptr;


    singola_riga_ = utente_input_.substr(utente_input_.find_first_of('{') +1, utente_input_.find_first_of(','));
    if(singola_riga_.empty() || singola_riga_.find("Nome_Gruppo:") == std::string::npos){
        std::cerr << "In " << utente_input_ << " il campo nome del gruppo non è definito correttamente" << std::endl;
    }else{
        singola_riga_ = singola_riga_.substr(singola_riga_.find_first_of(':') + 1, singola_riga_.find_first_of(','));
        singola_riga_.erase(singola_riga_.find_first_of(','));

        if (singola_riga_.empty()) {
            std::cerr << "In " << utente_input_ << " il campo nome è vuoto" << std::endl;
        }else {
            campo_nome_gruppo_ = singola_riga_;
            utente_input_ = utente_input_.erase(0, utente_input_.find_first_of(',') + 1);
            singola_riga_ = utente_input_.substr(0, utente_input_.find_first_of(','));

            if (singola_riga_.empty() || singola_riga_.find("Sede_Legale:") == std::string::npos) {
                std::cerr << "In " << utente_input_ << " il campo sede legale non è definito correttamente" << std::endl;
            } else {
                singola_riga_ = singola_riga_.substr(singola_riga_.find_first_of(':') + 1);
                if (singola_riga_.empty() || (std::all_of(singola_riga_.begin(),singola_riga_.end(),isdigit))) {
                    std::cerr << "In " << utente_input_ << " il campo sede legale è vuoto oppure ci sono caratteri errati" << std::endl;
                } else {
                    campo_sede_legale_ = singola_riga_;
                    utente_input_ = utente_input_.erase(0, utente_input_.find_first_of(',') + 1);
                    singola_riga_ = utente_input_.substr(0, utente_input_.find_first_of(','));

                    if (singola_riga_.empty() || singola_riga_.find("Tipo_Attività:") == std::string::npos) {
                        std::cerr << "In " << utente_input_ << " il campo attività non è definito correttamente" << std::endl;
                    } else {
                        singola_riga_ = singola_riga_.substr(singola_riga_.find_first_of(':') + 1);
                        if (singola_riga_.empty() || (std::all_of(singola_riga_.begin(), singola_riga_.end(), isdigit))) {
                            std::cerr << "In " << utente_input_ << " il campo tipo di attività è vuoto o il valore inserito è errato" << std::endl;
                        } else {
                            utente_input_ = utente_input_.erase(0, utente_input_.find_first_of(',') + 1);
                            campo_tipo_att_ = singola_riga_;
                            if (utente_input_.empty() || utente_input_.find("Utenti:") == std::string::npos) {
                                std::cerr << "il campo utenti non è definito correttamente" << std::endl;
                            } else {

                                utente_input_ = utente_input_.substr(utente_input_.find_first_of(':') + 1, utente_input_.find_last_not_of('}'));
                                utente_input_ = utente_input_.erase(utente_input_.find_last_of('}'));
                                if (utente_input_.empty() || std::all_of(utente_input_.begin(), utente_input_.end(), isalnum)) {
                                    std::cerr << "il campo utenti è vuoto o non è definito correttamente"
                                              << std::endl;
                                } else {
                                    ptr_g = new UtenteGruppo();
                                    ptr_g->setId(campo_id_);
                                    ptr_g->setTipo(campo_tipo_);
                                    ptr_g->setNomeGruppo(campo_nome_gruppo_);
                                    ptr_g->setSedeLegale(campo_sede_legale_);
                                    ptr_g->setTipoAttivita(campo_tipo_att_);
                                    ptr_g->setRelazioniId(utente_input_);
                                    utente_g_.push_back(*ptr_g);
                                    delete ptr_g;

                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


/*come in utente semplice*/
void FileDbClass::setUtenteAzienda(std::string utente_input_,const std::string &campo_id_,const std::string &campo_tipo_){
    std::string singola_riga_;
    std::string campo_nome_azienda_;
    std::string campo_sede_fiscale_;
    std::string campo_sede_operativa_;
    std::string campo_tipo_prodotto_;
    std::string campo_data_nascita_;

    UtenteAzienda *ptr_a = nullptr;


    singola_riga_ = utente_input_.substr(utente_input_.find_first_of('{') +1, utente_input_.find_first_of(','));
    if(singola_riga_.empty() || singola_riga_.find("Nome_Azienda:") == std::string::npos){
        std::cerr << "In " << utente_input_ << " il campo nome dell'azienda non è definito correttamente" << std::endl;
    }else{
        singola_riga_ = singola_riga_.substr(singola_riga_.find_first_of(':') + 1, singola_riga_.find_first_of(','));
        singola_riga_.erase(singola_riga_.find_first_of(','));

        if (singola_riga_.empty()) {
            std::cerr << "In " << utente_input_ << " il campo nome azienda è vuoto" << std::endl;
        }else {
            campo_nome_azienda_ = singola_riga_;

            utente_input_ = utente_input_.erase(0, utente_input_.find_first_of(',') + 1);
            singola_riga_ = utente_input_.substr(0, utente_input_.find_first_of(','));

            if (singola_riga_.empty() || singola_riga_.find("Sede_Fiscale:") == std::string::npos) {
                std::cerr << "In " << utente_input_ << " il campo sede fiscale non è definito correttamente" << std::endl;
            } else {
                singola_riga_ = singola_riga_.substr(singola_riga_.find_first_of(':') + 1);
                if (singola_riga_.empty() || (std::all_of(singola_riga_.begin(),singola_riga_.end(),isdigit))) {
                    std::cerr << "In " << utente_input_ << " il campo sede fiscale è vuoto oppure ci sono caratteri errati" << std::endl;
                } else {
                    campo_sede_fiscale_ = singola_riga_;

                    utente_input_ = utente_input_.erase(0, utente_input_.find_first_of(',') + 1);
                    singola_riga_ = utente_input_.substr(0, utente_input_.find_first_of(','));

                    if (singola_riga_.empty() || singola_riga_.find("Sede_Operativa:") == std::string::npos) {
                        std::cerr << "In " << utente_input_ << " il campo sede operativa non è definito correttamente" << std::endl;
                    } else {
                        singola_riga_ = singola_riga_.substr(singola_riga_.find_first_of(':') + 1);
                        if (singola_riga_.empty() || (std::all_of(singola_riga_.begin(), singola_riga_.end(), isdigit))) {
                            std::cerr << "In " << utente_input_ << " il campo sede operativa è vuoto o il valore inserito è errato" << std::endl;
                        } else {
                            campo_sede_operativa_ = singola_riga_;
                            utente_input_ = utente_input_.erase(0, utente_input_.find_first_of(',') + 1);
                            singola_riga_ = utente_input_.substr(0, utente_input_.find_first_of(','));

                            if (utente_input_.empty() || utente_input_.find("Tipo_Prodotto:") == std::string::npos) {
                                std::cerr << "il campo tipo di prodotto non è definito correttamente" << std::endl;
                            } else {
                                singola_riga_ = singola_riga_.substr(singola_riga_.find_first_of(':') + 1);
                                if (utente_input_.empty() || std::all_of(utente_input_.begin(), utente_input_.end(), isalnum)) {
                                    std::cerr << "il campo tipo di prodotto è vuoto o non è definito correttamente" << std::endl;
                                } else {
                                    campo_tipo_prodotto_ = singola_riga_;
                                    utente_input_ = utente_input_.erase(0, utente_input_.find_first_of(',') + 1);
                                    singola_riga_ = utente_input_.substr(0, utente_input_.find_first_of(','));

                                    if (utente_input_.empty() || utente_input_.find("Data_Di_Nascita:") == std::string::npos) {
                                        std::cerr << "il campo data di nascita non è definito correttamente" << std::endl;
                                    } else {
                                        singola_riga_ = singola_riga_.substr(singola_riga_.find_first_of(':') + 1);
                                        if (utente_input_.empty() || std::all_of(utente_input_.begin(), utente_input_.end(), isalnum)) {
                                            std::cerr << "il campo data di nascita è vuoto o non è definito correttamente" << std::endl;
                                        }else {
                                            campo_data_nascita_ = singola_riga_;
                                            utente_input_ = utente_input_.erase(0, utente_input_.find_first_of(',') + 1);
                                            singola_riga_ = utente_input_.substr(0, utente_input_.find_first_of(','));

                                            if (utente_input_.empty() || utente_input_.find("Relazioni:") == std::string::npos) {
                                                std::cerr << "il campo relazioni non è definito correttamente" << std::endl;
                                            } else {
                                                utente_input_ = utente_input_.substr(utente_input_.find_first_of(':') + 1, utente_input_.find_last_not_of('}'));
                                                utente_input_ = utente_input_.erase(utente_input_.find_last_of('}'));
                                                if (utente_input_.empty() || std::all_of(utente_input_.begin(), utente_input_.end(), isalnum)) {
                                                    std::cerr << "il campo relazioni è vuoto o non è definito correttamente" << std::endl;
                                                } else {
                                                    ptr_a = new UtenteAzienda();
                                                    ptr_a->setId(campo_id_);
                                                    ptr_a->setTipo(campo_tipo_);
                                                    ptr_a->setNomeAzienda(campo_nome_azienda_);
                                                    ptr_a->setSedeFiscale(campo_sede_fiscale_);
                                                    ptr_a->setSedeOperativa(campo_sede_operativa_);
                                                    ptr_a->setTipoProdotto(campo_tipo_prodotto_);
                                                    ptr_a->setDataNascita(campo_data_nascita_);
                                                    ptr_a->setRelazioniId(utente_input_);
                                                    utente_a_.push_back(*ptr_a);
                                                    delete ptr_a;

                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}



std::vector<UtenteSemplice> FileDbClass::getUtente() const {
    return utente_s_;
}


std::vector<UtenteGruppo> FileDbClass::getGruppo() const {
   return utente_g_;
}



std::vector<UtenteAzienda> FileDbClass::getAzienda() const {
    return  utente_a_;
}




RelationshipsClass::RelationshipsClass(const std::string &filename_) {
    nome_file_ = filename_;
}
/*
Attraverso un ciclo for si entra nella vector in cui ci sono le righe del file, si controlla che non ci siano righe
duplicate e infine, attraverso il metodo "trovaRigheErrate", si controlla che la singola riga sia coerente con la
formattazione del file
*/
int RelationshipsClass::formattazioneFileControl() {

    for(int i = 0; i != container_righe_.size(); ++i) {
        for (int j = i + 1; j != container_righe_.size(); ++j) {
            if (container_righe_[i] == container_righe_[j]) {
                std::cerr << "La riga numero " << i + 1 << " contenente " << container_righe_[i] << " è duplicata" << std::endl;
            }
        }
        if (trovaRigheErrate(container_righe_[i]) != 6) {
            std::cerr << "La riga numero " << i + 1 << " contenente " << container_righe_[i] << " non è coerente col file" << std::endl;
        }
    }
    return -1;
}



/*
Attraverso un ciclo for si entra nella vector in cui ci sono le righe del file, e ogni campo della vector viene salvato
in singola_riga_; successivamente su singola_riga_ viene 'spacchettata' nei campi: campo_id_, campo_tipo_ e
campo_utente_ tramite i metodi erase, e substr; Dopo ogni operazione di 'spacchettamento', di singola_riga_ viene
eliminata la parte relativa al campo appena creato fino ad ottenere alla fine del processo una stringa vuota.
Contemporaneamente, per il campo appena creato vengono effettuati dei controlli in relazione al tipo di campo, per
esempio: se è stato inizializzato il campo_id_, si controlla che il campo non sia vuoto o non alfanumerico e
successivamente si elimina da singola_riga_ la parte di stringa che corrisponde a campo_id; I tipi di relazione possibili sono quelli che si
 trovano in un file apposito, Relazioni.txt, che viene usato per controllare se una relazione è corretta. Infine se la relazione è corretta, viene inizializzato
 l'oggetto relativo ad una singola riga e l'oggeto stesso viene salvato in una vector di oggetti di tipo Relazione
*/
int RelationshipsClass::separaCampiFile() {

    std::string campo_id_1_;
    std::string campo_id_2_;
    std::string campo_relazione_;
    bool trovato_ = false;

    std::ifstream file_rel;

    for(int i = 0; i != container_righe_.size(); ++i) {
        singola_riga_ = container_righe_[i];
        campo_id_1_= singola_riga_.substr(0, singola_riga_.find_first_of(','));
        if((!std::all_of(campo_id_1_.begin(), campo_id_1_.end(), isalnum)) || campo_id_1_.empty() || (std::all_of(campo_id_1_.begin(), campo_id_1_.end(), isdigit))) {
            std::cerr << "La riga numero " << i + 1 << " contenente " << container_righe_[i] << " è errata, -2" << std::endl;
            return -2;
        }else{
            singola_riga_ = singola_riga_.erase(0, singola_riga_.find_first_of(',') + 1);

            campo_id_2_ = singola_riga_.substr(0, singola_riga_.find_first_of(','));
            if((!std::all_of(campo_id_1_.begin(), campo_id_1_.end(), isalnum) || campo_id_1_.empty()) || (std::all_of(campo_id_2_.begin(), campo_id_2_.end(), isdigit))){
                std::cerr << "La riga numero " << i + 1 << " contenente " << container_righe_[i] << " è errata, -3" << std::endl;
                return -3;
            }else{
                singola_riga_ = singola_riga_.erase(0, singola_riga_.find_first_of(',')+1);

                campo_relazione_ = singola_riga_;
                if(!std::all_of(campo_relazione_.begin(),campo_relazione_.end(),isalpha) ||  campo_relazione_.empty() || std::all_of(campo_relazione_.begin(),campo_relazione_.end(),isupper)){
                    std::cerr << "La riga numero " << i + 1 << " contenente " << container_righe_[i] << " è errata, -4" << std::endl;
                    return -4;
                }else{
                    file_rel.open("Relazioni.txt");
                    if(!file_rel.is_open()){
                        std::cout << "Errore nell'apertura del file Relazioni.txt" << std::endl;
                    }else {
                        while (getline(file_rel, singola_riga_)) {
                            if (campo_relazione_ == singola_riga_) {
                                trovato_ = true;
                            }
                        }
                        if (!trovato_) {
                            std::cout << "Il campo relazione " << campo_relazione_ << " non è presente tra le relazioni disponibili" << std::endl;
                        } else{
                            trovato_ = false;
                            rel_obj_.setId1(campo_id_1_);
                            rel_obj_.setId2(campo_id_2_);
                            rel_obj_.setRelazione(campo_relazione_);
                            container_relazioni_.push_back(rel_obj_);
                        }
                        file_rel.close();
                    }
                }
            }
        }
    }

    return -1;
}


std::vector<Relazioni> RelationshipsClass::getContainerRelazioni()const{
    return container_relazioni_;
}

SetofNewsClass::SetofNewsClass(const std::string& filename_){
    nome_file_ = filename_;

}


/*
Attraverso un ciclo for si entra nella vector in cui ci sono le righe del file, e ogni campo della vector viene salvato
in singola_riga_; si controlla che eliminando il contenuto di singola_riga_ fino al carattere '}', non
ci siano altri caratteri dopo quest'ultimo. Successivamente si controlla che non ci siano righe duplicate e infine,
attraverso il metodo "trovaRigheErrate", si controlla che in singola_riga ci sia una riga coerente con la formattazione del
file
 */
int SetofNewsClass::formattazioneFileControl() {

    for(int i = 0; i != container_righe_.size(); ++i){
        singola_riga_ = container_righe_[i];
        singola_riga_ = singola_riga_.erase(0,singola_riga_.find_last_of('}') + 1);
        for(int j = i + 1; j != container_righe_.size(); ++j){
            if(container_righe_[i] == container_righe_[j]){
                std::cerr << "La riga numero "<< i + 1 << " contenente "  << container_righe_[i] << " è duplicata" << std::endl;
            }
        }if(trovaRigheErrate(container_righe_[i]) != 6){
            std::cerr << "La riga numero " << i + 1 << " contenente " << container_righe_[i] << " non è coerente col file" << std::endl;
        }else if(!singola_riga_.empty()){
            std::cerr << "La riga numero " << i + 1 << " contenente " << container_righe_[i] << " ha dei caratteri dopo le parentesi" << std::endl;
        }
    }
    return -1;
}

/*
Si entra in un ciclo for di dimensione massima pari al numero di campi id presenti e controlla se sono dei campi id corretti,
 ovvero se sono alfanumerici, altrimenti manda un messaggio di errore
 */

int SetofNewsClass::controllaCorrettezzaid(std::string stringa_id_in_) {
    long int max_num_id = std::count(stringa_id_in_.begin(),stringa_id_in_.end(),',');
    std::string substring_id_singolo_;



    for(int i = 0; i <= max_num_id; ++i){
        substring_id_singolo_ = stringa_id_in_.substr(0,stringa_id_in_.find_first_of(','));

        if(std::all_of(substring_id_singolo_.begin(), substring_id_singolo_.end(), isdigit) || substring_id_singolo_.empty()
        || std::all_of(substring_id_singolo_.begin(), substring_id_singolo_.end(), isalpha)){
            std::cerr << "L'id " << substring_id_singolo_ << " non è un id corretto" << std::endl;
            return -1;
        }
        substring_id_singolo_ = stringa_id_in_.erase(0,stringa_id_in_.find_first_of(',') + 1);
    }
    return -2;
}


/*
Attraverso un ciclo for si entra nella vector in cui ci sono le righe del file, e ogni campo della vector viene salvato
in singola_riga_; successivamente su singola_riga_ viene 'spacchettata' nei campi: campo_id_, campo_tipo_ e
campo_utente_ tramite i metodi erase, e substr; Dopo ogni operazione di 'spacchettamento', di singola_riga_ viene
eliminata la parte relativa al campo appena creato fino ad ottenere alla fine del processo una stringa vuota.
Contemporaneamente, per il campo appena creato vengono effettuati dei controlli in relazione al tipo di campo, per
esempio: se è stato inizializzato il campo_id_, si controlla che il campo non sia vuoto o non alfanumerico e
successivamente si elimina da singola_riga_ la parte di stringa che corrisponde a campo_id; contemporaneamente controlla
tramite il metodo "controllaCorrettezzaid" che il campo dislike e like siano corretti, cioè che gli Id contenuti nella
riga siano alfanumerici
*/
int SetofNewsClass::separaCampiFile() {
    std::string campo_id_;
    std::string campo_messaggio_;
    std::string campo_like_;
    std::string campo_dislike_;

    NewsClass *ptr_ = nullptr;



    for(int i = 0; i != container_righe_.size(); ++i) {
        singola_riga_ = container_righe_[i];
        campo_id_= singola_riga_.substr(0, singola_riga_.find_first_of(','));
        if((!std::all_of(campo_id_.begin(), campo_id_.end(), isalnum)) || campo_id_.empty() || (std::all_of(campo_id_.begin(), campo_id_.end(), isdigit))) {
            std::cerr << "La riga numero " << i + 1 << " contenente " << container_righe_[i] << " è errata, -2" << std::endl;
        }else{
            singola_riga_ = singola_riga_.erase(0, singola_riga_.find_first_of(',') + 1);
            campo_messaggio_ = singola_riga_.substr(0,singola_riga_.find_last_of('"') + 1);
            if(campo_messaggio_.empty() || std::all_of(campo_messaggio_.begin(),campo_messaggio_.end(),isspace) || campo_messaggio_.find('"') == std::string::npos){
                std::cerr << "La riga numero " << i + 1 << " contenente " << container_righe_[i] << " è errata, -3" << std::endl;
            }else{
                campo_messaggio_ = campo_messaggio_.substr(1,campo_messaggio_.find_last_of('"'));
                campo_messaggio_ = campo_messaggio_.erase(campo_messaggio_.find_last_of('"'));

                singola_riga_ = singola_riga_.erase(0,singola_riga_.find_first_of(',') + 1);
                campo_like_ = singola_riga_.substr(0,singola_riga_.find_first_of('}'));

                if(campo_like_.find("Like:") == std::string::npos || campo_like_.empty()){
                    std::cerr << "In " << campo_like_ << " il campo like non è definito correttamente" << std::endl;
                }else{
                    campo_like_ = campo_like_.substr(campo_like_.find_first_of('{') + 1, campo_like_.find_last_of('}'));
                    if(controllaCorrettezzaid(campo_like_) == -1 || campo_like_.empty()){
                        std::cerr << "il campo like è vuoto o non è definito correttamente" << std::endl;
                    }else{
                        campo_dislike_= singola_riga_.erase(0,singola_riga_.find_first_of('}') + 2);
                        if(campo_dislike_.find("Dislike:") == std::string::npos || campo_dislike_.empty()){
                            std::cerr << "In " << campo_dislike_ << " il campo dislike non è definito correttamente" << std::endl;
                        }else {
                            campo_dislike_ = campo_dislike_.substr(campo_dislike_.find_first_of('{') + 1, campo_dislike_.find_last_of('}'));
                            campo_dislike_ = campo_dislike_.substr(0,campo_dislike_.find_last_of('}'));

                            if (controllaCorrettezzaid(campo_dislike_) == -1 || campo_dislike_.empty()) {
                                std::cerr << "il campo dislike è vuoto o non è definito correttamente" << std::endl;
                            }else{
                                ptr_ = new NewsClass();
                                ptr_->setId(campo_id_);
                                ptr_->setMessaggio(campo_messaggio_);
                                ptr_->setCampoLike(campo_like_);
                                ptr_->setCampoDislike(campo_dislike_);
                                container_news_.push_back(*ptr_);
                                delete ptr_;

                            }
                        }
                    }
                }
            }
        }
    }

    return -1;
}

std::vector<NewsClass> SetofNewsClass::getContainerNews() const {
    return container_news_;
}

