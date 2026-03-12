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

#include <stdio.h>

#include "string.h"
#include "uci.h"

void uci_loop(struct uci *uci)
{
	bool quit = false;

	while (!quit) {
		struct string user_input, command, args;
		string_init(&user_input);
		string_init(&command);
		string_init(&args);
		
		string_read_line(&user_input, stdin);

		string_split(&user_input, &command, &args, ' ');

		if (string_cmp_cstr(&command, "quit")) {
			quit = true;
		}
		
end_loop:
		string_destroy(&user_input);
	}
}
