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

#include <stdlib.h>

#include "string.h"

void string_init(struct string *s)
{
	s->mem = NULL;
	s->len = 0;
	s->cap = 0;
}

void string_destroy(struct string *s)
{
	free(s->mem);
	s->mem = NULL;
	s->len = 0;
	s->cap = 0;
}

void string_append(struct string *s, char c)
{
	// Must realloc if we run out of space for the string. We also must
	// consider the null terminator.
	if (s->len >= s->cap - 1) {
		s->mem = realloc(s->mem, (s->cap + 1) * 2);
		s->cap *= 2;
	}

	s->mem[s->len++] = c;
	s->mem[s->len]	 = '\0';
}

void string_append_range(struct string *s, char *mem, ptrdiff_t count)
{
	while (count != 0) {
		string_append(s, *mem++);
		count--;
	}
}

bool string_cmp_string(const struct string *lhs, const struct string *rhs)
{
	if (lhs->len != rhs->len)
		return false;

	for (int i = 0; i < lhs->len; ++i) {
		if (lhs->mem[i] != rhs->mem[i]) {
			return false;
		}
	}

	return true;
}

bool string_cmp_cstr(const struct string *s, const char *cstr)
{
	for (int i = 0; i < s->len; ++i) {
		if (s->mem[i] != cstr[i]) {
			return false;
		}
	}

	return true;
}

void string_split(const struct string *s, struct string *x, struct string *xs, char delim)
{
    string_init(x);
    string_init(xs);

    ptrdiff_t i = 0;

    while (i < s->len && s->mem[i] != delim) {
        string_append(x, s->mem[i]);
        ++i;
    }

    if (i < s->len && s->mem[i] == delim) {
        ++i;
    }
 
    while (i < s->len) {
        string_append(xs, s->mem[i++]);
    }
}

void string_read_line(struct string *s, FILE *file)
{
	int c;
	while ((c = fgetc(file)) != EOF && c != '\n') {
		string_append(s, (char)c);
	}
}
