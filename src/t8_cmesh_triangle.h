/*
  This file is part of t8code.
  t8code is a C library to manage a collection (a forest) of multiple
  connected adaptive space-trees of general element classes in parallel.

  Copyright (C) 2015 the developers

  t8code is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  t8code is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with t8code; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

/** \file t8_cmesh_triangle.h
 * We define function here that serve to open a mesh file generated by
 * TRIANGLE and consructing a cmesh from it.
 */

#ifndef T8_CMESH_TRIANGLE_H
#define T8_CMESH_TRIANGLE_H

#include <t8.h>
#include <t8_eclass.h>
#include <t8_cmesh.h>

/* put typedefs here */

T8_EXTERN_C_BEGIN ();

/* put declarations here */

/* Open a .node, .ele and .edge file to read cmesh.
 * and create a cmesh from them. the cmesh will be replicated.
 * (TODO: maybe allow for replicated input later)
 * We should only open the file on one process and
 * broadcast the information to the others before committing on each process.
 * A fully commited, replicated cmesh should be returned.
 */
t8_cmesh_t
t8_cmesh_from_triangle_file (char *filenames[], int partition, sc_MPI_Comm comm,
                             int do_dup);

T8_EXTERN_C_END ();

#endif /* !T8_CMESH_TRIANGLE_H */

