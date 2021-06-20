#include "resources_def.h"
#include "prototypes.h"

t_produit stock[TYPE_SIZE];
t_recette recettes[RECETTE_SIZE];
t_menu    menu_sem[MENU_SIZE];
t_db      db;
char      *recu = NULL;
int       choice = 0;

char *choices = "    CLIENT.                CHEF.\n"
"1. Passer une commande" " " "3. Creer menu" "\n"
"2. Recu" "                " "4. Recettes" "\n"
"       " "                " "5. Ingredient manquants" "\n"
"       " "                " "6. Historique des cmds" "\n"
"       " "                " "7. Stock" "\n";
char *instructions = "Faites votre choix, suivi des options:""\n"
                    "Ex. 1,2,5,0""\n"
                    "1 => Choix(Passer une commande)\n"
                    "2 => Option 1 (Id du menu)\n"
                    "5 => Option 2 (Qte Pour Repas 1)\n"
                    "0 => Option 3 (Qte Pour Repas 2)\n";

void init(void)
{
  bzero(stock, TYPE_SIZE * sizeof(t_produit));
  bzero(menu_sem, 7 * sizeof(t_menu));
  bzero(recettes, RECETTE_SIZE * sizeof(t_recette));

  // desérialisation
  // creer ou lire les fichier
  db.produits = fopen("db/produit", "a+");
  db.recettes = fopen("db/recette", "a+");
  db.repas = fopen("db/repas", "a+");
  db.menus = fopen("db/menu", "a+");
  db.cmds = fopen("db/cmd", "a+");
  restore_prod();
  restore_recette();
  restore_menus();
  // puts(menu_sem[0].recette[0]->nom);
}

int main(void) {
  t_recette rec;

  init();
  // add_menu((t_menu){1, &recettes[0]});
  do {
    aff_choix(choices, instructions);
  } while (choice != 9);
  return (0);
}

void  aff_choix(char *c_choices, char *c_ins)
{
  char *line = NULL;
  size_t len = 0;

  puts(c_choices);
  puts(c_ins);
  getline(&line, &len, stdin);
  choice = atoi(strtok(line, ","));
  switch(choice)
  {
    case 1: // get the order
      gestion_cmd();
      break ;
    case 2:
      puts("============================================");
      puts("                  RECU");
      puts("--------------------------------------------");
      if (recu == NULL)
        puts("Aucune Commande !");
      else
        puts(recu);
      puts("============================================");
      break ;
    case 3:
      gestion_menu();
      break ;
    case 4:
      afficher_recette();
      break ;
    case 5:
      produits_manquant();
      break ;
    case 6:
      afficher_cmds();
      break ;
    case 7:
      afficher_stock();
      break ;
    default:
      puts("Invalid choices.");
  }
}
  /*int i;
  menu[0]
  1,1,1,1
  for (i =0 ;i < MENU_SIZE; i++) 
  printf("%d,)*/
  // t_produit p = {1, "carottes", 33};
  // char *s = strdup("1,carottes,33");
  // t_produit p = prod_deserial(s);
  // t_produit p2 = {2, "Pommes", 12};
  // s = prod_serial(p);
  // puts(s);
//  creat_product(stock, db.produits, p);
//  creat_product(stock, db.produits, (t_produit){3, "Pommes", 12});
//  creat_product(stock, db.produits, (t_produit){4, "Choux", 56});
//   t_recette rec = (t_recette){1, "Pattes", 10000, {&stock[0], 78, &stock[1], 45, &stock[2], 90}};
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

  /*t_recette_elm liste_prod[3];
  stock[0] = p;
  stock[1] = p2;
  liste_prod[0] = (t_recette_elm){&stock[0], 10};
  liste_prod[1] = (t_recette_elm){&stock[1], 221};
  liste_prod[2] = (t_recette_elm){NULL, 0};
  update_stock(stock, liste_prod, db);*/