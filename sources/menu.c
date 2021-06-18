#include "resources_def.h"
#include "prototypes.h"

char *menu_serial(t_menu menu)
{

  int i;
  char *repas;
  char *tmp;    //variable temporaire
  size_t len;

  tmp = malloc(countD(menu.id) + 1);
  len = sprintf(tmp, "%d", menu.id);
  for (i = 0; i < 2; i++)
  {
    repas = malloc(len + strlen(menu.recette[i]->nom) + countD(menu.recette[i]->prix) + 3);
    len = sprintf(repas, "%s,%s-%d", tmp, menu.recette[i]->nom,
    menu.recette[i]->prix);
    free(tmp);
  }
  return(repas);
}

void save_menu(FILE *path, t_menu menu)
{
  char *result;

  result = menu_serial(menu);
  fprintf(path,"%s\n", result);
}

t_menu menus_deserial(char *line )
{
  t_menu menus;
  char *token;
  char *ptr;
  int i = 0;
  bzero(&menus, sizeof(t_menu));
  if (line == NULL)
    return(menus);
  token = strtok(strdup(line), ",");
  menus.id = atoi(token);
  while((token = strtok(NULL, ",")) && i < 2)
  {
    if (!(ptr = strchr(token, '-')))
      break ;
    *ptr = 0; // on separe les deux chaines
    puts(token);
    menu.recette[i]->nom =  token;
    menu.recette[i]->prix = atoi(ptr + 1); 
    i++;
  }
  return (menus);
}

