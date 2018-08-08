//Sono presenti le classi che definiscono i tipi di oggetti relativi ai tipi di righe che possono essere individuate nei file.
//In ogni classe vengono definiti i metodi privati o protetti per definire i campi e le member functions per settare i membri privati
//o protetti e per ritornare i metodi

#ifndef DATAUSERSCLASS_GENERICOUTENTE_H
#define DATAUSERSCLASS_GENERICOUTENTE_H

#include <iostream>
#include <string>
#include <vector>

class UtenteGenerico{
public:
    UtenteGenerico();

    void setId(const std::string &id_input_);
    void setTipo(const std::string &tipo_input_);
    void setDataNascita(const std::string &data_input_);
    //Controlla che gli id che specificano una relazione vengano salvati nella vector id_container_
    void setRelazioniId(std::string id_input_);


    std::string getId() const;
    std::string getTipo() const;
    std::string getDataNascita() const;
    //Restituisce la vector relativa agli id delle relazioni
    std::vector<std::string> getRelazioniId() const;


protected:
    std::string id_;
    std::string tipo_;
    std::string data_di_nascita;
    std::vector <std::string> id_container_;
    int day_;
    int month_;
    int year_;

};



class UtenteSemplice:public UtenteGenerico{
public:
    UtenteSemplice();


    void setNome(const std::string &nome_input_);
    void setCognome(const std::string &cognome_input_);
    void setSesso(const std::string &sesso_input_);

    std::string getNome() const;
    std::string getCognome() const;
    int getEta() const;
    std::string getSesso()const;

private:
    std::string nome_;
    std::string cognome_;
    std::string sesso_;
};



class UtenteGruppo:public UtenteGenerico{
public:
    UtenteGruppo();


    void setNomeGruppo(const std::string &nome_gruppo_input_);
    void setSedeLegale(const std::string &sede_legale_input_);
    void setTipoAttivita(const std::string &attivita_da_input_);


    std::string getNomeGruppo() const;
    std::string getSedeLegale() const ;
    std::string getTipoAttivita() const;

private:
    std::string nome_gruppo_;
    std::string sede_legale_;
    std::string tipo_attivita_;

};

class UtenteAzienda:public UtenteGenerico{
public:
    UtenteAzienda();

    void setNomeAzienda(const std::string &nome_azienda_input);
    void setSedeFiscale(const std::string &sede_fiscale_input);
    void setSedeOperativa(const std::string &sede_operativa_input);
    void setTipoProdotto(const std::string &tipo_prodotto_input);


    std::string getNomeAzienda() const;
    std::string getSedeFiscale() const;
    std::string getSedeOperativa() const;
    std::string getTipoProdotto() const;


private:
    std::string nome_azienda_;
    std::string sede_fiscale_;
    std::string sede_operativa_;
    std::string tipo_prodotto_;
};


class Relazioni{
public:
    Relazioni();
    void setRelazione(const std::string &relazione_in);
    void setId1(const std::string &id1_in);
    void setId2(const std::string &id2_in);

    std::string getRelazione() const;
    std::string getId1()const;
    std::string getId2()const;
private:
    std::string relazione_;
    std::string id1_;
    std::string id2_;
};

class NewsClass:public UtenteGenerico{
public:
    NewsClass();

    void setMessaggio(const std::string &messaggio_in_);
    void setCampoLike(std::string campo_like_in_);
    void setCampoDislike(std::string campo_dislike_in);

    std::string getCampoMessaggio()const;
    std::vector<std::string> getCampoLike()const;
    std::vector<std::string> getCampoDislike()const;

private:
    std::string messaggio_;
    std::vector<std::string> campo_like_;
    std::vector<std::string> campo_dislike_;

};


#endif //DATAUSERSCLASS_GENERICOUTENTE_H