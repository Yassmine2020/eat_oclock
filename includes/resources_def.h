#ifndef RES_DEF
# define RES_DEF
# define STOCK_SIZE 7
# include <time.h>

typedef struct product {
  int id;
  char *name;
} t_product;

float stock[STOCK_SIZE][2];

typedef struct recettes {
  int id;
  char *name;
  float liste[STOCK_SIZE][2];
} t_recette;

typedef struct repas {
  int id;
  char *name;
  int prix;
} t_repas;

typedef struct menu {
  int id;
  int liste_repas[2];
} t_menu;

typedef struct commande {
  int numero;
  int montant;
  int repas[2][2];
  t_time date;
} t_commande;
#endif