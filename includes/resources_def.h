#ifndef RES_DEF
# define RES_DEF
# define STOCK_SIZE 7

typedef struct product {
  int id;
  char *name;
} t_product;

float stock[STOCK_SIZE][2];

typedef struct recettes {
  int id;
  char *name;
  float liste[STOCK_SIZE][2];
} t_recette;
#endif
