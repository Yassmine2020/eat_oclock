//serialization
#include "resources_def.h"

t_produit stock[TYPE_SIZE];
t_db      db;

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
  fprintf(path,"%s\n", buffer);
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

  fseek(fichier, 0, SEEK_CUR);
  for(i = 0; i < TYPE_SIZE; i++)
  {
    if (stock[i].nom == NULL)
    {
      stock[i] = prod;
      fprintf(fichier, "%s\n", prod_serial(stock[i]));
      break;
    }
  }
}

t_produit *find_prod(char *nom_prod)
{
  int i;

  if (nom_prod != NULL)
    return (NULL);
  for(i = 0; i < TYPE_SIZE; i++)
  {
    if (strcmp(nom_prod, stock[i].nom) == 0) 
      return (&stock[i]);
  }
  return (NULL);
}

void produits_manquant(void)
{
  int i;

  puts("============ Ingredients Manquant ============");
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
  puts("==============================================");
}

void update_stock(t_produit *stock, t_recette_elm *liste_prod, t_db db)
{
  int i = 0;

  db.produits = freopen("db/produit", "w+", db.produits);// to clear the file
  // update each product of list
  while (liste_prod[i].produit != NULL)
  {
    liste_prod[i].produit->qte = liste_prod[i].produit->qte - liste_prod[i].qte;
    i++;
  }
  // update the stock
  for(i = 0; i < STOCK_SIZE; i++)
  {
    if (stock[i].nom == NULL)
      continue ;
    fprintf(db.produits, "%s\n", prod_serial(stock[i]));
  }
}

void restore_prod(void)
{
  char *line = NULL;
  size_t  n = 0;
  t_produit p;
  int i = 0;

  bzero(&p, sizeof(t_produit));
  while (getline(&line, &n, db.produits) > 1) {
    p = prod_deserial(line);
    if (find_prod(p.nom) == NULL)
      stock[i++] = p;
    if (i == STOCK_SIZE)
      break ;
    free(line);
    n = 0;
  }
}

void afficher_stock(void)
{
  char *line = NULL;
  size_t  n = 0;
  // t_recette rec;

  fseek(db.produits, 0, SEEK_SET);
  puts("=================== Stock ===================");
  while (getline(&line, &n, db.produits) > 1) {
    // rec = recettes_deserial(line);
    printf("%s", line);
    free(line);
    n = 0;
  }
  puts("==============================================");
}