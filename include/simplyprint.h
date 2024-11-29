#ifndef simplyprint_h
#define simplyprint_h

#include <simplyprint.h>

//Retourne les infos de l'imprimante aux travers de printf sur l'ecran
int ask_printer_name();

//Met en pause l'impression en cours
int pause_impression();

//Arrete l'impression en cours mais on doit la raison au travers d'id
//id = 1 --> Print failed         id = 2 --> Regretted print
int cancel_impression(int id);

//Met en pause l'impression
int resume_impression();

//une fois l'impression termine, 
//success = si l'impression est reussi    rating = evaluation de 1 a 4 du produit si l'impression est reussi
int clearbed_impression(bool success, int rating);

//Retourne le prix de l'impression
float getPrice_impression();

#endif