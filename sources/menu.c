#include "resources_def.h"
#include "prototypes.h"

t_produit stock[TYPE_SIZE];
t_menu    menu_sem[MENU_SIZE];
t_recette recettes[RECETTE_SIZE];
t_db      db;

void add_menu(t_menu menu)
{
  int i;

  db.menus = freopen("db/menu", "w+", db.menus);
  for (i = 0; i < MENU_SIZE; i++)
  {
    if (i == menu.id)
    {
      menu_sem[i].id = i;
      menu_sem[i].recette[0] = menu.recette[0];
      menu_sem[i].recette[1] = menu.recette[1];
    }
    printf("%p\n", menu_sem[i].recette[0]);
    if (menu_sem[i].recette[0] != NULL)
      fprintf(db.menus, "%d|%s,%d", i,menu_sem[i].recette[0]->nom, menu_sem[i].recette[0]->prix);
    if (menu_sem[i].recette[1] != NULL)
      fprintf(db.menus, "|%s,%d",
      menu_sem[i].recette[1]->nom, menu_sem[i].recette[1]->prix);
    if (menu_sem[i].recette[0] != NULL || menu_sem[i].recette[1] != NULL)
      fputs("\n", db.menus);
  }
  fflush(NULL); // to force the file update
    // exit(0); 
}

// id, name, price, name, price
void gestion_menu(void)
{
  int menu_id;
  t_recette *rec = NULL;
  char *opt = NULL;
  int prix = 0;
  t_menu menu;
  // TODO print help
  menu.id = atoi(strtok(NULL, ","));
  if (!(menu.id >= 0 && menu.id < MENU_SIZE)) {
    puts("Menu Invalid:\n" "Choix possibles [0-6]");
    return ;
  }
  opt = strtok(NULL, ",");
  rec = find_recette(opt);
  if (rec != NULL)
    menu.recette[0] = rec;
  opt = strtok(NULL, ",");
  rec = find_recette(opt);
  if (rec != NULL)
    menu.recette[1] = rec;
  add_menu(menu);
}

t_menu menus_deserial(char *line)
{
  t_menu menu;
  char *token;
  char *ptr;
  int i = 0;

  bzero(&menu, sizeof(t_menu));
  if (line == NULL)
    return(menu);
  token = strtok(line, "|");
  menu.id = atoi(token);
  while((token = strtok(NULL, "|")) && i < 2)
  {
    if (!(ptr = strchr(token, ',')))
      break ;
    *ptr = 0; // on separe les deux chaines
    // puts(token);
    menu.recette[i] = find_recette(token);
    i++;
  }
  return (menu);
}

void restore_menus(void)
{
  char *line = NULL;
  size_t  n = 0;
  t_menu menu;
  int i = 0;

  bzero(&menu, sizeof(t_menu));
  while (getline(&line, &n, db.menus) > 1) {
    menu = menus_deserial(line);
    // printf("[%p] [%p]\n", menu.recette[0], menu.recette[1]);
    menu_sem[i++] = menu;
    // puts(menu_sem[i - 1].recette[0]->nom);
    if (i == MENU_SIZE)
      break ;
    free(line);
    n = 0;
  }
  // exit(0);
}
// char *menu_serial(t_menu menu)
// {

//   int i;
//   char *repas;
//   char *tmp;    //variable temporaire
//   size_t len;

//   tmp = malloc(countD(menu.id) + 1);
//   len = sprintf(tmp, "%d", menu.id);
//   for (i = 0; i < 2; i++)
//   {
//     repas = malloc(len + strlen(menu.recette[i]->nom) + countD(menu.recette[i]->prix) + 3);
//     len = sprintf(repas, "%s,%s-%d", tmp, menu.recette[i]->nom,
//     menu.recette[i]->prix);
//     free(tmp);
//   }
//   return(repas);
// }