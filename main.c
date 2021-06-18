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
  db.produits = fopen("db/produit", "a+");
  db.recettes = fopen("db/recette", "a+");
  db.repas = fopen("db/repas", "a+");
  db.menus = fopen("db/menu", "a+");
  db.cmds = fopen("db/cmd", "a+");
  db.list = fopen("db/list", "a+");
}

int main(void)
{
  init();
  // t_produit p = {1, "carottes", 33};
  char *s = strdup("1,carottes,33");
  t_produit p = prod_deserial(s);
  t_produit p2 = {2, "Pommes", 12};
  s = prod_serial(p);
  // puts(s);
 // creat_product(stock, db.produits, p);
 // creat_product(stock, db.produits, (t_produit){2, "Pommes", 12});
 // creat_product(stock, db.produits, (t_produit){2, "Choux", 56});
  //t_recette rec = (t_recette){1, "Pattes", 10000, {&p, 78, &stock[1], 45, &stock[2], 90}};
  // t_recette rec;
  //save_recette(db.recettes, rec);
  // bzero(&rec, sizeof(t_recette));
  // rec.id = 1;
  // rec.nom = "Pattes";
  // rec.prix = 10000;
  // rec.elm[0].produit = &p;
  // rec.elm[0].qte = 23;

  //char *line = recette_serial(rec);
  // puts(line);
 // t_recette rece = recettes_deserial(line, stock);
 // puts(recette_serial(rece));
  //creat_recette(recettes, db.recettes, rece);
  //t_recette reca = (t_recette){2, "Kill", 450, {&p, 8, &stock[1], 44443}};
  //creat_recette(recettes, db.recettes, reca);
  /*stock[0] = (t_produit){1, "Kill", 450};
  stock[1] = (t_produit){2, "KilL me", 40};
  stock[2] = (t_produit){3, "KilL me please", 0};
  produits_manquant(stock);*/

t_recette_elm liste_prod[2];
 liste_prod[0] = (t_recette_elm){&p, 10};
 stock[0] = p;
 liste_prod[1]=(t_recette_elm){&p2, 221};
 stock[1] = p2;
 update_stock(liste_prod, db.list);
  return (0);
}