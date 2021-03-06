/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * Contributor(s): Campbell Barton
 *
 * ***** END GPL LICENSE BLOCK *****
 */

/** \file blender/editors/space_info/textview.h
 *  \ingroup spinfo
 */


typedef struct TextViewContext {
	int lheight;
	int sel_start, sel_end;

	/* view settings */
	int cwidth; /* shouldnt be needed! */
	int console_width; /* shouldnt be needed! */

	int winx;
	int ymin, ymax;
	
	/* callbacks */
	int (*begin)(struct TextViewContext *tvc);
	void (*end)(struct TextViewContext *tvc);
	void *arg1;
	void *arg2;

	/* iterator */
	int (*step)(struct TextViewContext *tvc);
	int (*line_get)(struct TextViewContext *tvc, const char **, int *);
	int (*line_color)(struct TextViewContext *tvc, unsigned char fg[3], unsigned char bg[3]);
	void *iter;
	int iter_index;
	int iter_char;		/* char intex, used for multi-line report display */
	int iter_char_next;	/* same as above, next \n */
	int iter_tmp;		/* internal iterator use */

} TextViewContext;

int textview_draw(struct TextViewContext *tvc, int draw, int mval[2], void **mouse_pick, int *pos_pick);

#define TVC_LINE_FG	(1<<0)
#define TVC_LINE_BG	(1<<1)
