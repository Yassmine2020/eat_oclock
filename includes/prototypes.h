#ifndef PROTOTYPES
#define PROTOTYPES

int countD(int n);
char *prod_serial(t_produit prod);
t_produit prod_deserial(char *line);
void creat_product(t_produit *stock, FILE *fichier, t_produit prod);
t_produit *find_prod(char *nom_prod);
void produits_manquant();
void update_stock(t_produit *stock, t_recette_elm *liste_prod, t_db db);

char *recette_serial(t_recette recette);
t_recette recettes_deserial(char *line);
void creat_recette(t_recette *recettes, FILE *fichier, t_recette rec);
void save_recette(FILE *path, t_recette recette);
int verif_rece(t_recette_elm *elm);
t_recette *find_recette(char *nom_rec);
void ingredients(t_recette rec);

void create_cmd(t_item *items);
char *get_recu(FILE *f_cmd);
// t_recette *find_rec(t_recette *recettes, char *nom);

void add_menu(t_menu menu);
void gestion_cmd(void);
void aff_choix(char *c_choices, char *c_ins);
void gestion_menu(void);
void restore_prod(void);
void afficher_recette(void);
void restore_recette(void);
void afficher_stock(void);
void afficher_cmds(void);
// char *menu_serial(t_menu menu);
// void save_menu(FILE *path, t_menu menu);
t_menu menus_deserial(char *line);
void restore_menus(void);
#endif