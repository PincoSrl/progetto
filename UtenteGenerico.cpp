//
// Created by eus on 13/06/18.
//

//
// Created by eus on 13/06/18.
//


#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include "UtenteGenerico.h"

UtenteGenerico::UtenteGenerico(){
    id_ = "";
    tipo_ = "";
    data_di_nascita = "";
    day_ = 0;
    month_ = 0;
    year_ = 0;
}


void UtenteGenerico::setId(const std::string &id_input_) {
    id_ = id_input_;
}

void UtenteGenerico::setTipo(const std::string &tipo_input_) {
    tipo_ = tipo_input_;
}

void UtenteGenerico::setDataNascita(const std::string &data_input_) {
    std::string singolo_campo_;

    singolo_campo_ = data_input_.substr(0,data_input_.find_first_of('/'));
    day_ = std::stoi(singolo_campo_);
    singolo_campo_ = data_input_.substr(data_input_.find_first_of('/') + 1,data_input_.find_last_of('/'));
    month_ = std::stoi(singolo_campo_);
    singolo_campo_ = data_input_.substr(data_input_.find_last_of('/') + 1);
    year_ = std::stoi(singolo_campo_);


    if(day_ <=0 || day_ > 31 ) std::cerr << "Il campo giorno con valore " << day_ << " è errato" << std::endl;
    else if(month_ <= 0 || month_ > 12) std::cerr << "Il campo mese con valore " << month_ << " è errato" << std::endl;
    else if(year_ < 705 || year_ > 2018 ) std::cerr << "Il campo anno con valore " << year_ << " è errato" << std::endl;
    else{
        data_di_nascita = data_input_;
    }
}

void UtenteGenerico::setRelazioniId(std::string id_input_) {

    long int max_num_id = std::count(id_input_.begin(),id_input_.end(),',');
    std::string substring_id_singolo_;


    for(int i = 0; i <= max_num_id; ++i){
        substring_id_singolo_ = id_input_.substr(0,id_input_.find_first_of(','));

        if(std::all_of(substring_id_singolo_.begin(), substring_id_singolo_.end(), isdigit) || substring_id_singolo_.empty() ||
           std::all_of(substring_id_singolo_.begin(), substring_id_singolo_.end(), isalpha)){
            std::cerr << "L'id " << substring_id_singolo_ << " non è un id corretto" << std::endl;
        }else{
            id_container_.push_back(substring_id_singolo_);

        }
        id_input_ = id_input_.erase(0,id_input_.find_first_of(',') + 1);
    }

}


std::string UtenteGenerico::getId() const {
    return id_;
}

std::string UtenteGenerico::getTipo() const {
    return tipo_;
}

std::string UtenteGenerico::getDataNascita() const {
    return data_di_nascita;
}

std::vector<std::string> UtenteGenerico::getRelazioniId() const {
    return id_container_;
}

UtenteSemplice::UtenteSemplice(){
    nome_ = "";
    cognome_ = "";
    sesso_ = ' ';
}

void UtenteSemplice::setNome(const std::string &nome_input_) {
    nome_ = nome_input_;
}

void UtenteSemplice::setCognome(const std::string &cognome_input_) {
    cognome_ = cognome_input_;
}

void UtenteSemplice::setSesso(const std::string &sesso_input_) {
        sesso_ = sesso_input_;
}

std::string UtenteSemplice::getNome() const {
    return nome_;
}

std::string UtenteSemplice::getCognome() const {
    return cognome_;
}

int UtenteSemplice::getEta() const {
    return 2018-year_;
}

std::string UtenteSemplice::getSesso() const {
    return sesso_;
}


UtenteGruppo::UtenteGruppo() {
    nome_gruppo_ = "";
    tipo_attivita_ = "";
    sede_legale_ = "";
}

void UtenteGruppo::setNomeGruppo(const std::string &nome_gruppo_input_) {
    nome_gruppo_ = nome_gruppo_input_;
}

void UtenteGruppo::setSedeLegale(const std::string &sede_legale_input_) {
    sede_legale_ = sede_legale_input_;
}

void UtenteGruppo::setTipoAttivita(const std::string &attivita_da_input_){
    tipo_attivita_ = attivita_da_input_;
}



std::string UtenteGruppo::getNomeGruppo() const {
    return nome_gruppo_;
}

std::string UtenteGruppo::getSedeLegale() const {
    return sede_legale_;
}

std::string UtenteGruppo::getTipoAttivita() const {
    return tipo_attivita_;
}



UtenteAzienda::UtenteAzienda(){
    tipo_ = "";
    nome_azienda_ = "";
    sede_fiscale_ = "";
    sede_operativa_ = "";
    tipo_prodotto_ = "";

}


void UtenteAzienda::setNomeAzienda(const std::string &nome_azienda_input){
    nome_azienda_ = nome_azienda_input;
}



void UtenteAzienda::setSedeFiscale(const std::string &sede_fiscale_input){
    sede_fiscale_ = sede_fiscale_input;
}

void UtenteAzienda::setSedeOperativa(const std::string &sede_operativa_input) {
    sede_operativa_ = sede_operativa_input;
}

void UtenteAzienda::setTipoProdotto(const std::string &tipo_prodotto_input) {
    tipo_prodotto_ = tipo_prodotto_input;
}


std::string UtenteAzienda::getNomeAzienda() const {
    return nome_azienda_;
}


std::string UtenteAzienda::getSedeFiscale() const {
    return sede_fiscale_;
}

std::string UtenteAzienda::getSedeOperativa() const {
    return sede_operativa_;
}

std::string UtenteAzienda::getTipoProdotto() const {
    return tipo_prodotto_;
}



Relazioni::Relazioni() {
    id1_ = "";
    id2_ = "";
    relazione_ = "";
}

void Relazioni::setRelazione(const std::string &relazione_in) {
    relazione_ = relazione_in;
}

void Relazioni::setId1(const std::string &id1_in) {
    id1_ = id1_in;
}

void Relazioni::setId2(const std::string &id2_in) {
    id2_ = id2_in;
}

std::string Relazioni::getRelazione() const {
    return relazione_;
}

std::string Relazioni::getId1() const {
    return id1_;
}

std::string Relazioni::getId2() const {
    return id2_;
}



NewsClass::NewsClass() {
    messaggio_ = "";
}

void NewsClass::setMessaggio(const std::string &messaggio_in_) {
    messaggio_ = messaggio_in_;
}

void NewsClass::setCampoLike(std::string campo_like_in_) {
    long int max_num_id = std::count(campo_like_in_.begin(),campo_like_in_.end(),',');
    std::string substring_id_singolo_;


    for(int i = 0; i <= max_num_id; ++i){
        substring_id_singolo_ = campo_like_in_.substr(0,campo_like_in_.find_first_of(','));

        if(std::all_of(substring_id_singolo_.begin(), substring_id_singolo_.end(), isdigit) || substring_id_singolo_.empty() ||
           std::all_of(substring_id_singolo_.begin(), substring_id_singolo_.end(), isalpha)){
            std::cerr << "L'id " << substring_id_singolo_ << " non è un id corretto" << std::endl;
        }else{
            campo_like_.push_back(substring_id_singolo_);
        }
        campo_like_in_ = campo_like_in_.erase(0,campo_like_in_.find_first_of(',') + 1);
    }
}

void NewsClass::setCampoDislike(std::string campo_dislike_in){
    long int max_num_id = std::count(campo_dislike_in.begin(),campo_dislike_in.end(),',');
    std::string substring_id_singolo_;

    for(int i = 0; i <= max_num_id; ++i){
        substring_id_singolo_ = campo_dislike_in.substr(0,campo_dislike_in.find_first_of(','));

        if(std::all_of(substring_id_singolo_.begin(), substring_id_singolo_.end(), isdigit) || substring_id_singolo_.empty() ||
           std::all_of(substring_id_singolo_.begin(), substring_id_singolo_.end(), isalpha)){
            std::cerr << "L'id " << substring_id_singolo_ << " non è un id corretto" << std::endl;
        }else{
            campo_dislike_.push_back(substring_id_singolo_);
        }
        campo_dislike_in = campo_dislike_in.erase(0,campo_dislike_in.find_first_of(',') + 1);
    }
}


std::string NewsClass::getCampoMessaggio() const {
    return messaggio_;
}

std::vector<std::string> NewsClass::getCampoLike() const {
    return campo_like_;
}

std::vector<std::string> NewsClass::getCampoDislike() const {
    return campo_dislike_;
}

