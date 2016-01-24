/*
 * This file is part of PoCrypt.
 * Copyright (c) David Martinez Oliveira
 *
 * PoCrypt is free software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * PoCrypt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PoCrypt.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdio.h>
#include "pocrypt.h"


SECURE_FUNC void
my_secure_function (char *str)
{
  printf ("You said: %s\n", str);
}

/* End of secure region mark */
SECURE_FUNC void dummy (){};

int 
main ()
{
  printf ("Hello. I'm a target\n");

  dump_mem ((unsigned char*)&my_secure_function, (unsigned char*)&dummy);
  decrypt_mem ((unsigned char*)&my_secure_function, (unsigned char*)&dummy);
  dump_mem ((unsigned char*)&my_secure_function, (unsigned char*)&dummy);

  my_secure_function ("Bye!\n");

  return 0;
}
 
