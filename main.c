#include "resources_def.h"
#include <stdio.h>
#include <strings.h>

t_produit stock[STOCK_SIZE];
t_recette recettes[RECETTE_SIZE];
t_repas   repas[14];
t_menu    menu_sem[7];
t_commande lst_cmd;
t_db      db;

void init(void)
{
  bzero(stock, sizeof(stock));
  bzero(menu_sem, sizeof(menu_sem));
  bzero(recettes, sizeof(recettes));
  bzero(repas, sizeof(repas));
  bzero(lst_cmd, sizeof(lst_cmd));

  // desérialisation
  // creer ou lire les fichier
  db.produit = fopen("db/produit", "w+");
  db.recette = fopen("db/recette", "w+");
  db.repas   = fopen("db/repas", "w+");
  db.menu    = fopen("db/menu", "w+");
  db.cmd     = fopen("db/cmd", "w+");
}

int main(void)
{
  init();
  return (a);
}