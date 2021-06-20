#include "resources_def.h"
#include "prototypes.h"

t_produit stock[TYPE_SIZE];
t_recette recettes[RECETTE_SIZE];
t_db      db;

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

t_recette recettes_deserial(char *line)
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
    // puts(token);
    recette.elm[i].produit = find_prod(token);
    recette.elm[i].qte = atoi(ptr + 1); 
    i++;
  }
  return (recette);
}

void creat_recette(t_recette *recettes, FILE *fichier, t_recette rec)
{
  int i;

  fseek(fichier, 0, SEEK_CUR);
  for(i = 0; i < RECETTE_SIZE; i++)
  {
    if (recettes[i].nom == NULL)
    {
      recettes[i] = rec;
      fprintf(fichier, "%s\n", recette_serial(recettes[i]));
      break;
    }
  }
}

int verif_rece(t_recette_elm *elm)
{
  int i;

  for (i = 0; i < TYPE_SIZE; i++) 
  {
    if (elm[i].produit == NULL)
      break;
    if (elm[i].produit->qte < elm[i].qte)
      return (0);
  }
  return(1);
}

t_recette *find_recette(char *nom_rec)
{
  int i;

  if (nom_rec == NULL)
    return (NULL);
  for (i = 0; i < RECETTE_SIZE; i++)
  {
    // printf("[%s] [%s]", recettes[i].nom, nom_rec);
    if (recettes[i].nom != NULL && strcmp(nom_rec, recettes[i].nom) == 0) 
      return (&recettes[i]);
  }
  return (NULL);
}

void ingredients(t_recette rec)
{
  int i;
  for (i = 0; i <TYPE_SIZE; i++ )
  printf("%s,%d",rec.elm[i].produit->nom,rec.elm[i].qte);
}

void restore_recette(void)
{
  char *line = NULL;
  size_t  n = 0;
  t_recette rec;
  int i = 0;

  bzero(&rec, sizeof(t_recette));
  while (getline(&line, &n, db.recettes) > 1) {
    rec = recettes_deserial(line);
    if (find_recette(rec.nom) == NULL)
      recettes[i++] = rec;
    if (i == RECETTE_SIZE)
      break ;
    free(line);
    n = 0;
  }
}

void afficher_recette(void)
{
  char *line = NULL;
  size_t  n = 0;
  // t_recette rec;

  fseek(db.recettes, 0, SEEK_SET);
  puts("================== Recettes ==================");
  while (getline(&line, &n, db.recettes) > 1) {
    // rec = recettes_deserial(line);
    printf("%s", line);
    free(line);
    n = 0;
  }
  puts("==============================================");
}
// void create_recette(t_recette *tab, FILE *fichier, t_recette recette)
// {
// tab[0]=recette.id;
// tab[1]=recette.nom;
// tab[2]=recette.;
// fprintf(fichier,"%d,%s,%d\n", recette.id, recette.nom, recette.qte);
// }