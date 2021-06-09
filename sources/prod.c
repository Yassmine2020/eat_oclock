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

  buffer = malloc(countD(prod.id) + countD(prod.qte) + strlen(prod.nom));
  sprintf(buffer, "%d,%s,%d\n", prod.id, prod.nom, prod.qte);
  return(buffer);
}

void save_product(FILE *path, t_produit prod)
{
  fprintf(path,"%d,%s,%d\n", prod.id, prod.nom, prod.qte);
}
