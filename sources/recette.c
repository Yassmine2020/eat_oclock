#include "resources_def.h"
#include "prototypes.h"

char *recette_serial(t_recette recette)
{
  int i;
  char *buf;
  char *tmp;
  size_t len;
  
  buf = malloc(countD(recette.id) + strlen(recette.nom) + countD
  (recette.prix) + 3);
  len = sprintf(buf, "%d,%s,%d", recette.id, recette.nom, recette.prix);
  tmp = buf;
  for (i = 0; i < TYPE_SIZE; i++)
  {
    if (recette.elm[i].produit == NULL)
      break ;
    // puts(recette.elm[i].produit->nom);
    buf = malloc(len + strlen(recette.elm[i].produit->nom) +
    countD(recette.elm[i].produit->qte) + 3);
    len = sprintf(buf, "%s,%s-%d", tmp, recette.elm[i]
    .produit->nom, recette.elm[i].qte);
    free(tmp);
    tmp = buf;
  }
  // puts("------");
  return(tmp);
}

void save_recette(FILE *path, t_recette recette)
{
  char *result;

  result = recette_serial( recette);
  fprintf(path,"%s\n", result);
}

t_recette recettes_deserial(char *line, t_produit *prods)
{
  t_recette  recette;
  char *token;
  char *ptr;
  int i = 0;

  bzero(&recette, sizeof(t_recette));
  if (line == NULL)
    return(recette);
  token = strtok(strdup(line), ",");
  recette.id = atoi(token);
  token = strtok(NULL, ",");
  recette.nom = token;
  token = strtok(NULL, ",");
  recette.prix = atoi(token);

  while((token = strtok(NULL, ",")) && i < TYPE_SIZE)
  {
    if (!(ptr = strchr(token, '-')))
      break ;
    *ptr = 0; // on separe les deux chaines
    puts(token);
    recette.elm[i].produit = find_prod(prods, token);
    recette.elm[i].qte = atoi(ptr + 1); 
    i++;
  }
  return (recette);
}

void creat_recette(t_recette *recettes, FILE *fichier, t_recette rec)
{
  int i;

  for(i = 0; i < RECETTE_SIZE; i++)
  {
    if (recettes[i].nom == NULL)
    {
      recettes[i] = rec;
      fseek(fichier, 0, SEEK_CUR);
      fprintf(fichier, "%s\n", recette_serial(recettes[i]));
      break;
    }
  }
}
// void create_recette(t_recette *tab, FILE *fichier, t_recette recette)
// {
// tab[0]=recette.id;
// tab[1]=recette.nom;
// tab[2]=recette.;
// fprintf(fichier,"%d,%s,%d\n", recette.id, recette.nom, recette.qte);
// }