#ifndef PROTOTYPES
#define PROTOTYPES

int countD(int n);
char *prod_serial(t_produit prod);
t_produit prod_deserial(char *line);
void creat_product(t_produit *stock, FILE *fichier, t_produit prod);
t_produit *find_prod(t_produit *produits, char *nom_prod);
void produits_manquant(t_produit *stock);
void update_stock(t_recette_elm *liste_prod, FILE *fichier);
void update_File(t_recette_elm *liste_prod, FILE *fichier1);

char *recette_serial(t_recette recette);
t_recette recettes_deserial(char *line, t_produit *prods);
void creat_recette(t_recette *recettes, FILE *fichier, t_recette rec);
void save_recette(FILE *path, t_recette recette);
int verif_rece(t_recette_elm *elm);
t_recette *find_recette(t_recette *recette, char *nom_rec);

void create_cmd(int *items, t_recette *recettes, FILE *fichier);
t_recette *find_rec(t_recette *recettes, int id_rec);

char *menu_serial(t_menu menu);
void save_menu(FILE *path, t_menu menu);
t_menu menus_deserial(char *line );
#endif