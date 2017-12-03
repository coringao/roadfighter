/*  Copyright 2003-2009 Santi Ontanon <santi.ontanon@terra.es>
    Work continued by 2017 Carlos Donizete Froes [a.k.a coringao]

    This file is part of Road Fighter Remake.

    Road Fighter Remake is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Road Fighter Remake is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Road Fighter Remake; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
*/

#ifndef __RF_TILE_CLASS
#define __RF_TILE_CLASS

#include "sge/sge_collision.h"

class CTile {
	friend class CObject;
	friend class CGame;

public:
	CTile(void);
	CTile(int x,int y,int dx,int dy,SDL_Surface *orig,bool collision);
	~CTile(void);

	void draw(int x,int y,SDL_Surface *dest);
	void draw_mask(int x,int y,SDL_Surface *dest);
	void draw_collision_mask(int x,int y,SDL_Surface *dest);

	void draw_scaled(int x,int y,SDL_Surface *dest,float scale);
	void draw_shaded(int x,int y,SDL_Surface *dest,int factor,int r,int g,int b,int a);
	void draw_bicolor(int x,int y,SDL_Surface *dest,int factor,int r1,int g1,int b1,int a1,int r2,int g2,int b2,int a2);

	void clear(void);
	void free(void);
	void instance(CTile *t);

	int get_dx(void) {return r.w;};
	int get_dy(void) {return r.h;};

private:

	SDL_Rect r;
	SDL_Surface *orig,*mask_visualization,*mask_collision;
	sge_cdata *collision_data;
};



/* TILE_SOURCE CLASS: */ 

class TILE_SOURCE {
	friend class CTile;
	friend class CGame;

public:
	TILE_SOURCE(void);
	TILE_SOURCE(char *filename);
	~TILE_SOURCE(void);

	bool save(FILE *fp);
	bool load(FILE *fp);

	bool cmp(char *n);

private:
	SDL_Surface *sfc;
	char *fname;
};


#endif

