/*
  Stilton - A UCI chess engine.
  Copyright (C) 2026 Amber Goulding

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef STILTON_STRING_H
#define STILTON_STRING_H

struct string {
	char	 *mem;
	ptrdiff_t len;
	ptrdiff_t cap;
};

void string_init(struct string *s);

void string_destroy(struct string *s);

void string_append(struct string *s, char c);

void string_append_mem(struct string *s, char *mem, ptrdiff_t count);

bool string_cmp_string(const struct string *lhs, const struct string *rhs);
bool string_cmp_cstr(const struct string *s, const char *cstr); 

void string_split(const struct string *s, struct string *x, struct string *xs, char delim);

void string_read_line(struct string *s, FILE *file);

#endif //STILTON_STRING_H
