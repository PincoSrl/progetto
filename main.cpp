#include <iostream>
#include "FileHandlingClass.h"
#include "DataUserClass.h"
#include "UtenteGenerico.h"

int main(int argc,char*argv[]) {
    FileDbClass db_content(argv[1]);
    RelationshipsClass rel_file_content(argv[2]);
    SetofNewsClass news_file_(argv[3]);




    if(argc != 4){
        std::cerr << "Numero di file inseriti non corretto" << std::endl;
    }else {
        if (db_content.aperturaFile() == -1) {
            std::cout << "Il file " << argv[1] << " è stato aperto correttamente" << std::endl;
            if(db_content.formattazioneFileControl() == -1){
                if(db_content.separaCampiFile() == -1){
                    std::cout << "#===================================================================================#"<< std::endl;
                    for(int i = 0; i < db_content.getUtente().size(); ++i) {
                        std::cout << db_content.getUtente()[i].getId() << ", " << db_content.getUtente()[i].getTipo()
                                  << ", " << db_content.getUtente()[i].getNome()
                                  << ", " << db_content.getUtente()[i].getCognome() << ", "
                                  << db_content.getUtente()[i].getSesso()
                                  << ", " << db_content.getUtente()[i].getDataNascita() << ", "
                                  << db_content.getUtente()[i].getEta() << std::endl;
                    }

                    std::cout << std::endl;
                    std::cout << "#===================================================================================#"<< std::endl;
                    for(int i = 0; i < db_content.getGruppo().size(); ++i) {
                        std::cout << db_content.getGruppo()[i].getId() << ", " << db_content.getGruppo()[i].getTipo()
                                  << ", " << db_content.getGruppo()[i].getNomeGruppo()
                                  << ", " << db_content.getGruppo()[i].getSedeLegale() << ", "
                                  << db_content.getGruppo()[i].getTipoAttivita() << ", " ;
                        for (int j = 0; j < db_content.getGruppo()[i].getRelazioniId().size(); ++j) {
                            std::cout << db_content.getGruppo()[i].getRelazioniId()[j] << " ";
                        }

                        std::cout << std::endl;
                    }

                    std::cout << std::endl;
                    std::cout << "#===================================================================================#"<< std::endl;

                    for(int i = 0; i < db_content.getAzienda().size(); ++i) {
                        std::cout << db_content.getAzienda()[i].getId() << ", " << db_content.getAzienda()[i].getTipo()
                                  << ", " << db_content.getAzienda()[i].getNomeAzienda()
                                  << ", " << db_content.getAzienda()[i].getSedeFiscale() << ", "
                                  << db_content.getAzienda()[i].getSedeOperativa()
                                  << ", " << db_content.getAzienda()[i].getTipoProdotto() << ", "
                                  << db_content.getAzienda()[i].getDataNascita() << ", ";
                        for (int j = 0; j < db_content.getAzienda()[i].getRelazioniId().size(); ++j) {
                            std::cout << db_content.getAzienda()[i].getRelazioniId()[j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;
                    std::cout << "#===================================================================================#"<< std::endl;



                }else{
                    //operazioni per modificare i campi
                }
            }/*else if(db_content.formattazioneFileControl() == -2){
                //operazioni per modificare le linee errate
            }*/
        }else if(db_content.aperturaFile() == -2){
            std::cerr << "Il file " << argv[1] << " è vuoto" << std::endl;
        }else if(db_content.aperturaFile() == -3){
            std::cerr << "Il file " << argv[1] << " non si trova nella cartella corrente" << std::endl;
        }else if(db_content.aperturaFile() == -4){
            std::cerr << "Il file " << argv[1] << " ha caratteri nel nome file non ammessi" << std::endl;
        }

        std::cout << "----------------------------------------------------------------------" << std::endl;
        if (rel_file_content.aperturaFile() == -1) {
            std::cout << "Il file " << argv[2] << " è stato aperto correttamente" << std::endl;
            if(rel_file_content.formattazioneFileControl() == -1){
                if(rel_file_content.separaCampiFile() == -1){
                    std::cout << std::endl;
                    std::cout << "#===================================================================================#"<< std::endl;

                    for(int i = 0; i < rel_file_content.getContainerRelazioni().size(); ++i){
                        std::cout << rel_file_content.getContainerRelazioni()[i].getId1() << ", " << rel_file_content.getContainerRelazioni()[i].getId2()
                                  << ", " << rel_file_content.getContainerRelazioni()[i].getRelazione() << std::endl;
                    }

                }else{
                    //operazioni per modificare i campi,eventualmente
                }
            }/*else if(rel_file_content.formattazioneFileControl() == -2){
                //operazioni per modificare le linee errate,eventualmente
            }*/
        }else if(rel_file_content.aperturaFile() == -2){
            std::cerr << "Il file " << argv[2] << " è vuoto" << std::endl;
        }else if(rel_file_content.aperturaFile() == -3){
            std::cerr << "Il file " << argv[2] << " non si trova nella cartella corrente" << std::endl;
        }else if(rel_file_content.aperturaFile() == -4){
            std::cerr << "Il file " << argv[2] << " ha caratteri nel nome file non ammessi" << std::endl;
        }
    }

    std::cout << "----------------------------------------------------------------------" << std::endl;

    if (news_file_.aperturaFile() == -1) {
        std::cout << "Il file " << argv[3] << " è stato aperto correttamente" << std::endl;
        if(news_file_.formattazioneFileControl() == -1){
            if(news_file_.separaCampiFile() == -1){
                std::cout << std::endl;
                std::cout << "#===================================================================================#"<< std::endl;

                for(int i = 0; i < news_file_.getContainerNews().size(); ++i) {
                    std::cout << news_file_.getContainerNews()[i].getId() << ", "
                    << news_file_.getContainerNews()[i].getCampoMessaggio() << ", ";
                    for (int j = 0; j < news_file_.getContainerNews()[i].getCampoLike().size() ; ++j) {
                        std::cout << news_file_.getContainerNews()[i].getCampoLike()[j] << " ";
                    }
                    for (int k = 0; k < news_file_.getContainerNews()[i].getCampoDislike().size() ; ++k) {
                       std::cout << news_file_.getContainerNews()[i].getCampoDislike()[k] << " ";
                    }
                    std::cout << std::endl;
                }

            }else{
                //operazioni per modificare i campi,eventualmente
            }
        }/*else if(news_file_.formattazioneFileControl() == -2){
            //operazioni per modificare le linee errate,eventualmente
        }*/
    }else if(news_file_.aperturaFile() == -2){
        std::cerr << "Il file " << argv[3] << " è vuoto" << std::endl;
    }else if(news_file_.aperturaFile() == -3){
        std::cerr << "Il file " << argv[3] << " non si trova nella cartella corrente" << std::endl;
    }else if(news_file_.aperturaFile() == -4){
        std::cerr << "Il file " << argv[3] << " ha caratteri nel nome file non ammessi" << std::endl;
    }




    return 0;
}