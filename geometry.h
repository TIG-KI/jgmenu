/*
 * geometry.h contains algorithms for calculating menu co-ordinates.
 *
 * The program window has no border or padding, so the menu_* variables
 * can be thought of as window_* variables. In fact, when the X11 window
 * is created/resized/moved the menu_margin_x, etc are used.
 *
 * Definitions:
 *			screen
 *	+---------------------------------------+
 *	|					|
 *	|	   menu				|
 *	|	+--------+			|
 *	|	|  item	 |			|
 *	|	| +----+ |			|
 *	|	| |    | |			|
 *	|	| +----+ |			|
 *	|	|	 |			|
 *	|	| +----+ |			|
 *	|	| |    | |			|
 *	|	| +----+ |			|
 *	|	|	 |			|
 *	|	+--------+			|
 *	+---------------------------------------+
 *
 * "margin" is space outside an object.
 * "padding" is space inside an object (between border and content).
 * (x0, y0) represents the top left corner of the screen/menu/item.
 * (x1, y1) represents the bottom right corner of the screen/menu/item.
 *
 * The menu_margin_* is the distance between the X11 window and the edge
 * of the screen
 *
 * "itemarea" refers to the area occupied by menu-items (incl item_margin*)
 *
 * Usage:
 * ------
 *   - Init X11 (XOpenDisplay, etc)
 *   - Call geo_init()
 *   - All the geo_get_* can now be used (default values set up geo_init)
 *   - Set variables using the geo_set_* functions.
 *     These all call geo_update() which updates all "geometry" variables.
 *
 */

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "x11-ui.h"
#include "align.h"

void geo_update(void);
void geo_init(void);
int geo_get_item_coordinates(struct area *a);
struct point geo_get_max_itemarea_that_fits_on_screen(void);

void geo_set_menu_width(int w);
void geo_set_menu_width_from_itemarea_width(int w);
void geo_set_menu_height(int h);
void geo_set_menu_height_from_itemarea_height(int h);
void geo_set_menu_margin_x(int x);
void geo_set_menu_margin_y(int y);
void geo_set_menu_halign(enum alignment pos);
void geo_set_menu_valign(enum alignment pos);
void geo_set_item_height(int h);
void geo_set_nr_visible_items(int nr);
void geo_set_item_margin_x(int margin);
void geo_set_item_margin_y(int margin);

int geo_get_menu_x0(void);
int geo_get_menu_y0(void);
int geo_get_menu_height(void);
int geo_get_itemarea_height(void);
int geo_get_menu_width(void);
int geo_get_menu_width_from_itemarea_width(int w);
int geo_get_item_height(void);
int geo_get_screen_height(void);
int geo_get_screen_width(void);
int geo_get_nr_visible_items(void);

#endif  /* GEOMETRY_H */
