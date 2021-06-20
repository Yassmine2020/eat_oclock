#ifndef RES_DEF
# define RES_DEF
# define TYPE_SIZE 10
# define STOCK_SIZE 10
# define RECETTE_SIZE 14
# define TAUX_MINIMALE 100
# define MENU_SIZE 7
#define _GNU_SOURCE
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct menu {
  int id;
  t_recette *recette[2];
} t_menu;

typedef struct db {
  FILE *produits;
  FILE *recettes;
  FILE *repas;
  FILE *menus;
  FILE *cmds;
} t_db;

typedef struct item {
  t_recette *recette;
  int qte;
} t_item;
#endif