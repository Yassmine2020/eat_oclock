#include "resources_def.h"
#include "prototypes.h"

// void create_cmd(int *items, t_recette *recettes, FILE *fichier)
// {
//   static int numero;
//   int total;
//   t_recette *rec;
//   time_t now;
//   struct tm instant;

//   rec = find_rec(recettes, items[0]);
//   total = rec->prix * items[1];
//   rec = find_rec(recettes, items[2]);
//   total += rec->prix * items[3];
//   time(&now);
//   instant = *localtime(&now);
//   fprintf(fichier, "%d-%d-%d,%d,%d-%d,%d-%d\n", instant.tm_mon + 1, instant.tm_mday,
//   instant.tm_hour + 1, numero, total, items[0], items[1],items[2],items[3]);
// }

t_recette *find_rec(t_recette *recettes, int id_rec)
{
  int i;

  for(i = 0; i < RECETTE_SIZE; i++)
  {
    if (id_rec == recettes[i].id) 
      return (&recettes[i]);
  }
  return (NULL);
}


/*t_commande cmd_deserial(char *line)
{
  t_commande  cmd;
  char *token;
  char *ptr;
  int i = 0;

  bzero(&prod, sizeof(t_cmd));
  if (line == NULL)
    return (cmd);
  token = strtok(strdup(line), ",");
  cmd.numero = atoi(token);
  token = strtok(NULL, ",");
  prod.montant = atoi(token);
  token = strtok(NULL, ",");
   while((token = strtok(NULL, ",")) && i < 2)
  {
    if (!(ptr = strchr(token, '-')))
      break ;
    *ptr = 0; // on separe les deux chaines
    puts(token);
    cmd.repas[i] = find_prod(prods, token);
    recette.elm[i].qte = atoi(ptr + 1); 
    i++;
  }
  return (cmd);
}*/