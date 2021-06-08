#ifndef RES_DEF
# define RES_DEF
# define TYPE_SIZE 10
# define RECETTE_SIZE 14
# include <time.h>

typedef struct produit {
  int id;
  char *nom;  
  float qte;
} t_produit;

typedef struct recette_elm {
  t_produit *produit;
  float     qte;
} t_recette_elm;

typedef struct recettes {
  int id;
  char *nom;
  t_recette_elm elm[TYPE_SIZE];
} t_recette;

typedef struct repas {
  int id;
  char *nom;
  int prix;
  t_recette *recettes;
} t_repas;

typedef struct menu {
  int id;
  t_repas *repas[2];
} t_menu;

typedef struct commande {
  int numero;
  int montant;
  int repas[2][2];
  t_time date;
  t_commande *next;
} t_commande;

typedef struct db {
  FILE *produit;
  FILE *recettes;
  FILE *repas;
  FILE *menu;
  FILE *cmd;
} t_db;
#endif