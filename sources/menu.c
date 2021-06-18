#include "resources_def.h"
#include "prototypes.h"

char *menu_serial(t_menu menu)
{

  int i;
  char *repas;
  char *tmp;    //variable temporaire
  int len;

  tmp = malloc(countD(menu.id) + 1);
  len = sprintf(tmp, "%d", menu.id);
  for (i = 0; i < 2; i++)
  {
    repas = malloc(len + strlen(menu.recette[i]->nom) + countD(menu.recette[i]->prix) + 3);
    len = sprintf(repas, "%s,%s-%d", tmp, menu.recette[i]->nom,
    menu.recette[i]->prix);
    free(tmp);
    tmp = repas;
  }
  return(tmp);
}

