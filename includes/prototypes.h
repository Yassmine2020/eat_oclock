#ifndef PROTOTYPES
#define PROTOTYPES

int countD(int n);
char *prod_serial(t_produit prod);
t_produit prod_deserial(char *line);
void creat_product(t_produit *stock, FILE *fichier, t_produit prod);
t_produit *find_prod(t_produit *produits, char *nom_prod);

char *recette_serial(t_recette recette);
void save_recette(FILE *path, t_recette recette);
t_recette recettes_deserial(char *line, t_produit *prods);
void creat_recette(t_recette *recettes, FILE *fichier, t_recette rec);

void create_cmd(int *items, t_recette *recettes, FILE *fichier);
#endif