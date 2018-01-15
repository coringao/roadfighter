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


CFuelObject::CFuelObject(int nx,int ny,CTile *t,CGame *g) : CObject(nx,ny,t,CONSTITUTION_FUEL,g)
{
	y_speed=0;
	y_precision=0;

	state=0;

	x_speed=0;
	x_precision=0;
} /* CFuelObject::CFuelObject */ 


CFuelObject::~CFuelObject(void)
{
} /* CFuelObject::~CFuelObject */ 



bool CFuelObject::cycle(unsigned char *keyboard,unsigned char *old_keyboard)
{
	y_precision+=y_speed;
	while(y_precision>(1<<8)) {
		y++;
		y_precision-=1<<8;
	} /* while */ 
	while(y_precision<(1<<8)) {
		y--;
		y_precision+=1<<8;
	} /* while */ 

	x_precision+=x_speed;
	while(x_precision>(1<<8)) {
		x++;
		x_precision-=1<<8;
	} /* while */ 
	while(x_precision<(1<<8)) {
		x--;
		x_precision+=1<<8;
	} /* while */ 

	y_speed=-ENEMY_SPEED;

	y_speed=-ENEMY_SPEED;
	x_speed=0;
	if (game->object_collision(16,0,this,CONSTITUTION_SOLID)!=0) {
		x_speed=-ENEMY_HSPEED;
	} else {
		if (game->object_collision(-16,0,this,CONSTITUTION_SOLID)!=0) {
			x_speed=ENEMY_HSPEED;
		} /* if */ 
	} /* if */ 

	if (game->min_distance_to_players(y)>PLAYING_WINDOW) return false;
	
	return true;
} /* CFuelObject::cycle */ 

