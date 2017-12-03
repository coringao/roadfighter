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

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

#include "sound.h"

#include "CTile.h"
#include "CObject.h"
#include "CGame.h"

CExplosionObject::CExplosionObject(int nx,int ny,List<CTile> *l,int first_tile,int last_tile,CGame *g)
{
	int i;

	state=0;

	ntiles=(last_tile-first_tile)+1;
	tiles=new CTile *[(last_tile-first_tile)+1];

	for(i=0;i<(last_tile-first_tile)+1;i++) tiles[i]=l->operator [](i+first_tile);

	game=g;
	tile=0;

	x=nx;
	y=ny;
	draw_x=nx;
	draw_y=ny;
	constitution=CONSTITUTION_NONE;

	timmer=0;

} /* CExplosionObject::CExplosionObject */ 


CExplosionObject::~CExplosionObject(void)
{
} /* CExplosionObject::~CExplosionObject */ 



bool CExplosionObject::cycle(unsigned char *keyboard,unsigned char *old_keyboard)
{
	timmer++;

	tile=timmer/2;
	if (tile>=ntiles) return false;

	return true;
} /* CExplosionObject::cycle */ 
