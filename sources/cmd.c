#include "resources_def.h"
#include "prototypes.h"

t_produit stock[TYPE_SIZE];
t_menu    menu_sem[MENU_SIZE];
t_db      db;
char      *recu;

void create_cmd(t_item *items)
{
  static int numero = 1;
  int total = 0;
  t_recette *rec = NULL;
  time_t now;
  struct tm vtime;
  int i = 0;

  rec = items[0].recette;
  // printf("[%d] [%d]\n", items[0].qte, items[1].qte);
  while (rec != NULL && i < items[0].qte) {
    if (verif_rece(rec->elm) == 1) {
      update_stock(stock, rec->elm, db);
      total += rec->prix * items[0].qte;
    }
    i++;
  }
  // printf("[%d] [%d]\n", rec->prix, total); 
  rec = items[1].recette;
  i = 0;
  while (rec != NULL && i < items[1].qte) {
    if (verif_rece(rec->elm) == 1) {
      update_stock(stock, rec->elm, db);
      total += rec->prix * items[1].qte;
    }
    i++;
  }
  time(&now);
  vtime = *localtime(&now);
  fprintf(db.cmds, "%dh %d/%d,", vtime.tm_hour + 1, vtime.tm_mday, vtime.tm_mon + 1);
  fprintf(db.cmds, "%05d,%d", numero, total);
  if (items[0].recette != NULL)
    fprintf(db.cmds, ",%s,%d", items[0].recette->nom, items[0].qte);
  if (items[1].recette != NULL)
    fprintf(db.cmds, ",%s,%d", items[1].recette->nom, items[1].qte);
  fputs("\n", db.cmds);
  numero++;
}

void gestion_cmd(void)
{
  int menu_id;
  t_item items[2];
  // TODO print help
  menu_id = atoi(strtok(NULL, ","));
  items[0].recette = menu_sem[menu_id].recette[0];
  items[1].recette = menu_sem[menu_id].recette[1];
  items[0].qte = atoi(strtok(NULL, ","));
  items[1].qte = atoi(strtok(NULL, ","));
  // exit(0);
  create_cmd(items);
  recu = get_recu(db.cmds);
}

char *get_recu(FILE *f_cmd)
{
  char *line = NULL;
  char *tmp = NULL;
  size_t  n = 0;

  fseek(f_cmd, 0, SEEK_SET);
  while (getline(&tmp, &n, f_cmd) > 1) {
    free(line);
    line = tmp;
    n = 0;
  }
  return(line);
}

void afficher_cmds(void)
{
  char *line = NULL;
  size_t  n = 0;
  // t_recette rec;

  fseek(db.cmds, 0, SEEK_SET);
  puts("============ Historique Commandes ============");
  while (getline(&line, &n, db.cmds) > 1) {
    // rec = recettes_deserial(line);
    printf("%s", line);
    free(line);
    n = 0;
  }
  puts("==============================================");
}

// t_commande cmd_deserial(char *line)
// {
//   t_commande  cmd;
//   char *token;
//   char *ptr;
//   int i = 0;

//   bzero(&prod, sizeof(t_cmd));
//   if (line == NULL)
//     return (cmd);
//   token = strtok(strdup(line), ",");
//   cmd.numero = atoi(token);
//   token = strtok(NULL, ",");
//   prod.montant = atoi(token);
//   token = strtok(NULL, ",");
//    while((token = strtok(NULL, ",")) && i < 2)
//   {
//     if (!(ptr = strchr(token, '-')))
//       break ;
//     *ptr = 0; // on separe les deux chaines
//     puts(token);
//     cmd.repas[i] = find_prod(prods, token);
//     recette.elm[i].qte = atoi(ptr + 1); 
//     i++;
//   }
//   return (cmd);
// }