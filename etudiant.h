#include <gtk/gtk.h>




typedef struct
{
    char nom[40];
    char prenom[40];
    char sexe[40];
    char date_naissance[40];
    char cin[40];
    char gsm[40];
    char niveaux[40];
    char id[40];
    char username[40];
    char password[40];
    int num_etage;
    int num_ch;
    char type_ch[40];
}Etudiant;

int verif_pass(char log[], char pw[]);
void ajouter_et(Etudiant p);
void rechercher_ett(GtkWidget *liste,char ch[30] );
void supprimer_ett (char id1[20]);
void modifier_ett(char id1[],Etudiant r);








