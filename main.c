#include "resources_def.h"
#include "prototypes.h"

t_produit stock[TYPE_SIZE];
t_recette recettes[RECETTE_SIZE];
t_repas   repas[14];
t_menu    menu_sem[7];
t_commande lst_cmd;
t_db      db;

void init(void)
{
  bzero(stock, TYPE_SIZE * sizeof(t_produit));
  bzero(menu_sem, 7 * sizeof(t_menu));
  bzero(recettes, RECETTE_SIZE * sizeof(t_recette));
  bzero(repas, 14 * sizeof(t_repas));
  bzero(&lst_cmd, sizeof(t_commande));

  // desérialisation
  // creer ou lire les fichier
  db.produits = fopen("db/produit", "w+");
  db.recettes = fopen("db/recette", "w+");
  db.repas = fopen("db/repas", "w+");
  db.menus = fopen("db/menu", "w+");
  db.cmds = fopen("db/cmd", "w+");
}

int main(void)
{
  init();
  t_produit p = {1, "carottes", 33};
  char *s;

  s = prod_serial(p);
  return (0);
}