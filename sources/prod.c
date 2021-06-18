//serialization
#include "resources_def.h"

int countD(int n)
{
    int count = 0;

    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

char *prod_serial(t_produit prod)
{
  char *buffer;

  buffer = malloc(countD(prod.id) + countD(prod.qte) + strlen(prod.nom) + 5);
  sprintf(buffer, "%d,%s,%d\n", prod.id, prod.nom, prod.qte);
  return(buffer);
}

void save_product(FILE *path, t_produit prod)
{
  char *buffer;                                //c'est m pas déclarer en prototype
  buffer = prod_serial(prod);
  fprintf(path,"%s", buffer);
}

t_produit prod_deserial(char *line)
{
  t_produit  prod;
  char *token;

  bzero(&prod, sizeof(t_produit));
  if (line == NULL)
    return (prod);
  token = strtok(strdup(line), ",");
  prod.id = atoi(token);
  token = strtok(NULL, ",");
  prod.nom = token;
  token = strtok(NULL, ",");
  prod.qte = atoi(token);
  return (prod);
}

void creat_product(t_produit *stock, FILE *fichier, t_produit prod)
{
  int i;

  for(i = 0; i < TYPE_SIZE; i++)
  {
    if (stock[i].nom == NULL)
    {
      stock[i] = prod;
      fseek(fichier, 0, SEEK_CUR);
      fprintf(fichier, "%s", prod_serial(stock[i]));
      break;
    }
  }
}

t_produit *find_prod(t_produit *stock, char *nom_prod)
{
  int i;
  t_produit *produit = NULL;
  for(i = 0; i < TYPE_SIZE; i++)
  {
    if (strcmp(nom_prod, stock[i].nom) == 0) 
      return (&stock[i]);
  }
  return (produit);
}