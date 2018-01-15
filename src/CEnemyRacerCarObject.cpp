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

#include "math.h"

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#include "sound.h"

#include "CTile.h"
#include "CObject.h"
#include "CGame.h"

extern int ENEMY_SPEED;
extern int ENEMY_HSPEED;
extern int PLAYING_WINDOW;


CEnemyRacerCarObject::CEnemyRacerCarObject(int nx,int ny,CTile *t,int start_delay,CGame *g) : CEnemyCarObject(nx,ny,t,start_delay,g)
{
	advanced=false;
} /* CEnemyRacerCarObject::CEnemyRacerCarObject */ 


CEnemyRacerCarObject::~CEnemyRacerCarObject(void)
{
} /* CEnemyRacerCarObject::~CEnemyRacerCarObject */ 



bool CEnemyRacerCarObject::cycle(unsigned char *keyboard,unsigned char *old_keyboard)
{
	bool retval=true;

	retval=CEnemyCarObject::cycle(keyboard,old_keyboard);

	if (!advanced && game->min_distance_to_players(y)<48 && y_speed!=0) {
		advanced=true;
		if (game->S_caradvance!=0) Sound_play(game->S_caradvance);
	} /* if */ 

	return retval;
} /* CEnemyRacerCarObject::cycle */ 

