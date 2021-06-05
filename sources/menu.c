void create_menu(t_menu *menus, int repas1, int repas2)
{
  static int id;
  
  menus[id].id = id;
  menus[id].liste_repas = {repas1, repas2};
  id++;
}

t_menu find_menu(t_menu *menus, int id)
{
  return (menus[id]);
}