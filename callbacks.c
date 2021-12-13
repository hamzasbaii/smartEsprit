#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "etudiant.c"

Etudiant o;
char sexe1[10]="Homme";
char zz[10]="";
int conf1=0;



void
on_go_ajouter_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");
gtk_widget_destroy(afficher_et);
GtkWidget *ajouter_et;
ajouter_et = create_ajouter_et ();
  gtk_widget_show (ajouter_et);
}


void
on_go_supprimer_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");

GtkWidget *supprimer_et;
supprimer_et = create_supprimer_et ();
  gtk_widget_show (supprimer_et);
}


void
on_go_modifier_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");
gtk_widget_destroy(afficher_et);

    char nom[40];
    char prenom[40];
    char sexe[40];
    char date_naissance[40];
    char cin[40];
    char gsm[40];
    char niveaux[40];
    char id[10];
    char username[40];
    char password[40];
    char num_etage[40];
    char num_ch[40];
    char type_ch[40];
FILE *f;

f=fopen("etudiant.txt","r");
GtkWidget *Modifier_et;
Modifier_et = create_Modifier_et ();
gtk_widget_show (Modifier_et);

GtkWidget *nom_et1;
nom_et1 = lookup_widget (Modifier_et ,"nom_et1");
GtkWidget *prenom_et1;
prenom_et1 = lookup_widget (Modifier_et ,"prenom_et1");
GtkWidget *cin_et1;
cin_et1 = lookup_widget (Modifier_et ,"cin_et1");
GtkWidget *tel_et1;
tel_et1 = lookup_widget (Modifier_et ,"tel_et1");
GtkWidget *username_et1;
username_et1 = lookup_widget (Modifier_et ,"username_et1");
GtkWidget *password_et1;
password_et1 = lookup_widget (Modifier_et ,"password_et1");

while(fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s \n",id,nom,prenom,cin,sexe,date_naissance,gsm,username,password,num_etage,num_ch,type_ch,niveaux)!=EOF){
 if (strcmp(o.id,id)==0){
       gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"nom_et1")),nom);
       gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"prenom_et1")),prenom);
       gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"cin_et1")),cin);
       gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"tel_et1")),gsm);
       gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"username_et1")),username);
       gtk_entry_set_text(GTK_ENTRY(lookup_widget(Modifier_et,"password_et1")),password);

}}
}


void
on_actualiser_user_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1_et;
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");
treeview1_et=lookup_widget(afficher_et,"treeview1_et");
afficher_ett(treeview1_et);
}


void
on_deconn_user_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");
gtk_widget_destroy(afficher_et);
GtkWidget *window1;
window1 = create_auth_et ();
gtk_widget_show (window1);
}


void
on_treeview1_et_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* prenom;
	gchar* cin;
	gchar* sexe;
	gchar* dns;
	gchar* gsm;
	gchar* niv;
	gchar* username;
	gchar* password;
	gchar* etage;
	gchar* chambre;
	gchar* type;
	

	GtkTreeModel *model =gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{ 
	  gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0 , &id, 1, &nom,2,&prenom,3,&cin,4,&sexe,5,&dns,6,&gsm,7,&niv,8,&username,9,&password,10,&etage,11,&chambre,12,&type,-1);
	strcpy(o.id,id);strcpy(zz,id);
	
	}
}

void
on_chercher_et_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cherch;
char ch[20];
GtkWidget *treeview1_user;
GtkWidget *afficher_et;
afficher_et=lookup_widget(button,"afficher_et");

treeview1_user=lookup_widget(afficher_et,"treeview1_et");
cherch = lookup_widget (button ,"entry1_chercher");
strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherch)));
 rechercher_ett(treeview1_user,ch);
}

void
on_ajouter_et_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
int aa,mm,jj;
char a[3];
char b[3];
char c[6];
char y[15]="";

int x=0;
Etudiant p;
GtkWidget *calendar1_et;
GtkWidget *id_et,*nom_et,*prenom_et,*cin_et,*tel_et,*comboboxentry1_et,*comboboxentry2_et;
GtkWidget *spinbutton1_et;
GtkWidget *username_et,*password_et,*cin_user,*num_etage,*num_ch;

calendar1_et=lookup_widget(button,"calendar1_et");

nom_et=lookup_widget(button,"entre_nomet");
prenom_et=lookup_widget(button,"entre_prenom_et");
cin_et=lookup_widget(button,"entre_cinet");
tel_et=lookup_widget(button,"entre_telet");
password_et=lookup_widget(button,"entre_passwordet");
username_et=lookup_widget(button,"entre_usernameet");


comboboxentry1_et=lookup_widget(button,"comboboxentry1_et");
comboboxentry2_et=lookup_widget(button,"comboboxentry2_et");
id_et=lookup_widget(button,"entre_id");
num_etage=lookup_widget(button,"spinbutton2_et");
num_ch=lookup_widget(button,"spinbutton3_et");




GtkWidget *e_id;
e_id = lookup_widget (button ,"e_id");
GtkWidget *e_nom;
e_nom = lookup_widget (button ,"e_nom");
GtkWidget *e_prenom;
e_prenom = lookup_widget (button ,"e_prenom");
GtkWidget *e_cin;
e_cin = lookup_widget (button ,"e_cin");
GtkWidget *e_num;
e_num = lookup_widget (button ,"e_num");
GtkWidget *e_username;
e_username = lookup_widget (button ,"e_username");
GtkWidget *e_password;
e_password = lookup_widget (button ,"e_password");
GtkWidget *e_niveaux;
e_niveaux = lookup_widget (button ,"e_niveaux");
GtkWidget *e_typeet;
e_typeet = lookup_widget (button ,"e_typeet");
GtkWidget *e_confet;
e_confet = lookup_widget (button ,"e_confet");


int bbb=0;
gtk_calendar_get_date (GTK_CALENDAR(calendar1_et),
                       &aa,
                       &mm,
                       &jj);

mm=mm+1;

sprintf(a,"%d",jj);sprintf(b,"%d",mm);sprintf(c,"%d",aa);
strcat(y,a);strcat(y,"-");strcat(y,b);strcat(y,"-");strcat(y,c);


p.num_etage=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(num_etage));
p.num_ch=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(num_ch));

strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(id_et)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom_et)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom_et)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(cin_et)));
strcpy(p.gsm,gtk_entry_get_text(GTK_ENTRY(tel_et)));
strcpy(p.username,gtk_entry_get_text(GTK_ENTRY(username_et)));
strcpy(p.password,gtk_entry_get_text(GTK_ENTRY(password_et)));



strcpy(p.date_naissance,y);
strcpy(p.niveaux,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1_et)));
strcpy(p.type_ch,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2_et)));

strcpy(p.sexe,sexe1);

if (strcmp(p.id,"")==0)
{x=1;
gtk_widget_show(e_id);
}
else {x=0;
gtk_widget_hide(e_id);
}
if (strcmp(p.nom,"")==0)
{x=1;
gtk_widget_show(e_nom);
}
else {x=0;
gtk_widget_hide(e_nom);
}
if (strcmp(p.prenom,"")==0)
{x=1;
gtk_widget_show(e_prenom);
}
else {x=0;
gtk_widget_hide(e_prenom);
}
if (strcmp(p.cin,"")==0)
{x=1;
gtk_widget_show(e_cin);
}
else {x=0;
gtk_widget_hide(e_cin);
}
if (strcmp(p.gsm,"")==0)
{x=1;
gtk_widget_show(e_num);
}
else {x=0;
gtk_widget_hide(e_num);
}
if (strcmp(p.username,"")==0)
{x=1;
gtk_widget_show(e_username);
}
else {x=0;
gtk_widget_hide(e_username);
}
if (strcmp(p.password,"")==0)
{x=1;
gtk_widget_show(e_password);
}
else {x=0;
gtk_widget_hide(e_password);
}
if (strcmp(p.niveaux,"")==0)
{x=1;
gtk_widget_show(e_niveaux);
}
else {x=0;
gtk_widget_hide(e_niveaux);
}
if (strcmp(p.type_ch,"")==0)
{x=1;
gtk_widget_show(e_typeet);
}
else {x=0;
gtk_widget_hide(e_typeet);
}
if (conf1==0)
{x=1;
gtk_widget_show(e_confet);
}
else {
gtk_widget_hide(e_confet);
}


if(x==0){
ajouter_et(p);
GtkWidget *ajouter_et;
ajouter_et=lookup_widget(button,"ajouter_et");
gtk_widget_destroy(ajouter_et);
GtkWidget *afficher_et;
afficher_et = create_afficher_et ();
  gtk_widget_show (afficher_et);
}}




void
on_modifier_et_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{


Etudiant p;


GtkWidget *nom_et1;
nom_et1 = lookup_widget (button ,"nom_et1");
GtkWidget *prenom_et1;
prenom_et1 = lookup_widget (button ,"prenom_et1");
GtkWidget *cin_et1;
cin_et1 = lookup_widget (button ,"cin_et1");
GtkWidget *tel_et1;
tel_et1 = lookup_widget (button ,"tel_et1");
GtkWidget *username_et1;
username_et1 = lookup_widget (button ,"username_et1");
GtkWidget *password_et1;
password_et1 = lookup_widget (button ,"password_et1");





GtkWidget *e_nom;
e_nom = lookup_widget (button ,"e_nom1");
GtkWidget *e_prenom;
e_prenom = lookup_widget (button ,"e_prenom1");
GtkWidget *e_cin;
e_cin = lookup_widget (button ,"e_cin1");
GtkWidget *e_num;
e_num = lookup_widget (button ,"e_tel1");
GtkWidget *e_username;
e_username = lookup_widget (button ,"e_username1");
GtkWidget *e_password;
e_password = lookup_widget (button ,"e_password1");




int x=0;



strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom_et1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom_et1)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(cin_et1)));
strcpy(p.gsm,gtk_entry_get_text(GTK_ENTRY(tel_et1)));
strcpy(p.username,gtk_entry_get_text(GTK_ENTRY(username_et1)));
strcpy(p.password,gtk_entry_get_text(GTK_ENTRY(password_et1)));
if (strcmp(p.nom,"")==0)
{x=1;
gtk_widget_show(e_nom);
}
else {x=0;
gtk_widget_hide(e_nom);
}
if (strcmp(p.prenom,"")==0)
{x=1;
gtk_widget_show(e_prenom);
}
else {x=0;
gtk_widget_hide(e_prenom);
}
if (strcmp(p.cin,"")==0)
{x=1;
gtk_widget_show(e_cin);
}
else {x=0;
gtk_widget_hide(e_cin);
}
if (strcmp(p.gsm,"")==0)
{x=1;
gtk_widget_show(e_num);
}
else {x=0;
gtk_widget_hide(e_num);
}
if (strcmp(p.username,"")==0)
{x=1;
gtk_widget_show(e_username);
}
else {x=0;
gtk_widget_hide(e_username);
}
if (strcmp(p.password,"")==0)
{x=1;
gtk_widget_show(e_password);
}
else {x=0;
gtk_widget_hide(e_password);
}


if (x==0){

 modifier_ett(o.id,p);
GtkWidget *Modifier_et;
Modifier_et=lookup_widget(button,"Modifier_et");
gtk_widget_destroy(Modifier_et);
GtkWidget *afficher_et;
afficher_et = create_afficher_et ();
  gtk_widget_show (afficher_et);

}}


void
on_retour_ajouteret_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_et;
ajouter_et=lookup_widget(button,"ajouter_et");
gtk_widget_destroy(ajouter_et);
GtkWidget *afficher_et;
afficher_et = create_afficher_et ();
  gtk_widget_show (afficher_et);
}


void
on_retour_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Modifier_et;
Modifier_et=lookup_widget(button,"Modifier_et");
gtk_widget_destroy(Modifier_et);
GtkWidget *afficher_et;
afficher_et = create_afficher_et ();
  gtk_widget_show (afficher_et);
}


void
on_annuler_supp_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *supprimer_et;
supprimer_et=lookup_widget(button,"supprimer_et");
gtk_widget_destroy(supprimer_et);
GtkWidget *afficher_et;

  gtk_widget_show (afficher_et);
}


void
on_conf_supp_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
supprimer_ett(o.id);
GtkWidget *supprimer_et;
supprimer_et=lookup_widget(button,"supprimer_et");
gtk_widget_destroy(supprimer_et);
GtkWidget *afficher_et;

  gtk_widget_show (afficher_et);
}


void
on_radiobutton1_et_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(sexe1,"Homme");
}


void
on_radiobutton2_et_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(sexe1,"Femme");
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
conf1=1;
}


void
on_auth_et_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *erreur_pass;

erreur_pass = lookup_widget(button,"e_auth");

GtkWidget *username, *password, *windowAcceuil_hsm;
char user[20];
char passw[20];
int trouve;
username = lookup_widget (button, "username_et");
password = lookup_widget (button, "password_et");
strcpy(user ,gtk_entry_get_text ( GTK_ENTRY(username)));
strcpy(passw ,gtk_entry_get_text ( GTK_ENTRY(password)));
trouve=verif_pass(user,passw);
if (trouve==1)
{

GtkWidget *window1;
window1=lookup_widget(button,"auth_et");
gtk_widget_destroy(window1);
GtkWidget *afficher_et;
afficher_et = create_afficher_et ();
  gtk_widget_show (afficher_et);
}
else if (trouve==-1){gtk_widget_show (erreur_pass);}
}


void
on_inns_ett_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
window1=lookup_widget(button,"auth_et");
gtk_widget_destroy(window1);
GtkWidget *inscri_et;
inscri_et = create_inscri_et ();
  gtk_widget_show (inscri_et);
}


void
on_insc_et_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f=NULL;
GtkWidget *login, *pw;
char login1[40];
char passw[40];
login = lookup_widget(button,"entry1_ett");
pw = lookup_widget(button,"entry2_ett");
strcpy(login1,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(passw,gtk_entry_get_text(GTK_ENTRY(pw)));
f=fopen("utilisateur.txt","a+");
if (f != NULL)
{
fprintf(f,"%s %s \n",login1,passw);

}
fclose(f);
GtkWidget *inscri_et;
inscri_et=lookup_widget(button,"inscri_et");
gtk_widget_destroy(inscri_et);
GtkWidget *auth_et;
auth_et = create_auth_et ();
  gtk_widget_show (auth_et);

}


void
on_anul_ins_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *inscri_et;
inscri_et=lookup_widget(button,"inscri_et");
gtk_widget_destroy(inscri_et);
GtkWidget *auth_et;
auth_et = create_auth_et ();
  gtk_widget_show (auth_et);
}


void
on_stat_etttttt_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
char nnn[20];
char a[20];
int s;
GtkWidget *comboboxentry3_et;
comboboxentry3_et=lookup_widget(button,"comboboxentry3_et");

GtkWidget *nbr_ettt;
nbr_ettt=lookup_widget(button,"nbr_ettt");

strcpy(nnn,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry3_et)));
s = stat(nnn);
sprintf(a,"%d",s);
gtk_label_set_text(GTK_LABEL(nbr_ettt),a);
}







