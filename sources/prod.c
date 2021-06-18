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
  sprintf(buffer, "%d,%s,%d", prod.id, prod.nom, prod.qte);
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

  for(i = 0; i < TYPE_SIZE; i++)
  {
    if (strcmp(nom_prod, stock[i].nom) == 0) 
      return (&stock[i]);
  }
  return (NULL);
}

void produits_manquant(t_produit *stock)
{
  int i;

  for (i = 0; i < TYPE_SIZE; i++)
  {
    if (!stock[i].nom)
      break ;
    if (stock[i].qte < TAUX_MINIMALE)
    {
      printf("%s - [%d]\n", prod_serial(stock[i]),
      TAUX_MINIMALE - stock[i].qte);
    }
  }
}

void update_File(t_recette_elm *liste_prod, FILE *fichier1)
{
  int i;
  for (i = 0; i < TYPE_SIZE; i++)
  {
    fseek(fichier1, 0, SEEK_CUR);
    fprintf(fichier1, "%s", prod_serial(*(liste_prod[i].produit)));
  }
}

void update_stock(t_recette_elm *liste_prod, FILE *fichier)
{
  int i;

  for(i = 0; i < TYPE_SIZE; i++)
   {
    if (liste_prod[i].produit == NULL)
      break ;
      liste_prod[i].produit->qte = liste_prod[i].produit->qte -
      liste_prod[i].qte;
      update_File(liste_prod, fichier);
    }
}