/*
 * Copyright (C) 2010 gonzoj
 *
 * Please check the CREDITS file for further information.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef USER_INTERFACE_H_
#define USER_INTERFACE_H_

typedef enum {
	UI_BLACK = 0,
	UI_RED = 1,
	UI_GREEN = 2,
	UI_YELLOW = 3,
	UI_BLUE = 4,
	UI_MAGENTA = 5,
	UI_CYAN = 6,
	UI_WHITE = 7
} ui_color;

#define COLOR(c) if (isatty(STDOUT_FILENO)) printf("\033[3%dm", c)
#define BOLD() if (isatty(STDOUT_FILENO)) printf("\033[1m")
#define COLOR_RESET() if (isatty(STDOUT_FILENO)) printf("\033[0m")

// exported
void ui_console_lock();

// exported
void ui_console_unlock();

// exported
void ui_print(int, char *, ...);

#define print(f, s...) ui_print(UI_WHITE, f,  ## s)

#define error(f, s...) ui_print(UI_RED, f, ## s)

// exported
void ui_print_plugin(int, char *, char *, ...);

#define plugin_print(p, f, s...) ui_print_plugin(UI_GREEN, p, f, ## s)

#define plugin_error(p, f, s...) ui_print_plugin(UI_RED, p, f, ## s)

// exported
void ui_print_debug(int, char *, ...);

#define debug(f, s...) ui_print_debug(UI_YELLOW, f, ## s)

// exported
void ui_print_debug_plugin(int, char *, char *, ...);

#define plugin_debug(p, f, s...) ui_print_debug_plugin(UI_YELLOW, p, f, ## s)

typedef void (*ui_cmd_t)(int, char **);

// exported
bool ui_register_cmd(char *, ui_cmd_t);

// exported
bool ui_unregister_cmd(char *, ui_cmd_t);

void ui_invoke_cmd(char *);

// exported
void ui_add_statistics(char *, ...);

// exported
void ui_add_statistics_plugin(char *, char *, ...);

void ui_print_statistics();

void ui_start();

void ui_stop();

#endif /* USER_INTERFACE_H_ */
