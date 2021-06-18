#include "resources_def.h"
#include "prototypes.h"

void create_cmd(int *items, t_recette *recettes, FILE *fichier)
{
  static int numero;
  int total;
  t_recette *rec;
  time_t now;
  struct tm instant;

  rec = find_rec(recettes, items[0]);
  total = rec->prix * items[1];
  rec = find_rec(recettes, items[2]);
  total += rec->prix * items[3];
  time(&now);
  instant = *localtime(&now);
  fprintf(fichier, "%d-%d-%d,%d,%d-%d,%d-%d\n", instant.tm_mon + 1, instant.tm_mday,
  instant.tm_hour + 1, numero, total, items[0], items[1],items[2],items[3]);
}