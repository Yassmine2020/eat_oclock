#ifndef RES_DEF
# define RES_DEF
# define TYPE_SIZE 10
# define RECETTE_SIZE 14
# define TAUX_MINIMALE 100
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct produit {
  int id;
  char *nom; 
  int qte;
} t_produit;

typedef struct recette_elm {
  t_produit *produit;
  int     qte;
} t_recette_elm;

typedef struct recettes {
  int id;
  char *nom;
  int prix;
  t_recette_elm elm[TYPE_SIZE];
} t_recette;

typedef struct repas {
  char *nom;
  int prix;
  t_recette *recettes;
} t_repas;

typedef struct menu {
  int id;
  t_recette *recette[2];
} t_menu;

typedef struct commande t_commande;

struct commande {
  int numero;
  int montant;
  int repas[2][2];
  time_t date;
};

typedef struct db {
  FILE *produits;
  FILE *recettes;
  FILE *repas;
  FILE *menus;
  FILE *cmds;
  FILE *list;
} t_db;

typedef struct items {
  char *nom ;
  int qte;
} t_items;
#endif