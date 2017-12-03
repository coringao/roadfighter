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

#ifdef _WIN32
#include <windows.h>
#include <windowsx.h>
#else
#include <sys/time.h>
#include <time.h>
#endif
#include "math.h"

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

#include "sound.h"

#include "CTile.h"
#include "CObject.h"
#include "CGame.h"

#include "auxiliar.h"

extern int MAX_SPEED;
extern int ENEMY_SPEED;
extern int ENEMY_HSPEED;
extern int PLAYING_WINDOW;

CEnemyCarObject::CEnemyCarObject(int nx,int ny,CTile *t,int start_delay,CGame *g) : CCarObject(nx,ny,t,g)
{
	state_timmer=start_delay;

	following_right_border=true;
	distance_to_border=-1;
	last_collision=0;

	slide_timmer=0;
} /* CEnemyCarObject::CEnemyCarObject */ 


CEnemyCarObject::~CEnemyCarObject(void)
{
} /* CEnemyCarObject::~CEnemyCarObject */ 



bool CEnemyCarObject::cycle(unsigned char *keyboard,unsigned char *old_keyboard)
{
	CCarObject::cycle(keyboard,old_keyboard);

	if (state_timmer>0) state_timmer--;
	if (state==0 && state_timmer==0) state=1;

	if (last_collision!=0) {
		if (last_collision->get_x()<x) slide_direction=1;
								  else slide_direction=-1;
		slide_speed=min(last_collision->get_y_speed(),y_speed);
		slide_timmer=8;

		last_collision=0;
	} /* if */ 

	if (state!=0) {
		y_speed=-ENEMY_SPEED;
		x_speed=0;
		if (game->object_collision(8,0,this,CONSTITUTION_SOLID)!=0) {
			x_speed=-ENEMY_HSPEED;
			slide_timmer=0;
		} else {
			if (game->object_collision(-8,0,this,CONSTITUTION_SOLID)!=0) {
				x_speed=ENEMY_HSPEED;
				slide_timmer=0;
			} /* if */ 
		} /* if */ 

		if (slide_timmer>0) {
			slide_timmer--;
			if (slide_direction==1) x_speed=int(ENEMY_HSPEED);
			if (slide_direction==-1) x_speed=-int(ENEMY_HSPEED);
			y_speed=slide_speed;
		} /* if */ 

		if (x_speed==0 && distance_to_border!=-1) {
			int i;
			int distance=-1;
			for(i=0;distance==-1 && i<=distance_to_border+8;i+=8) {
				if (following_right_border) {
					if (game->object_collision(i,0,this,CONSTITUTION_SOLID)!=0) distance=i-8;
				} else {
					if (game->object_collision(-i,0,this,CONSTITUTION_SOLID)!=0) distance=i-8;
				} /* if */ 
			} /* for */ 
			if (distance==-1) distance=distance_to_border+8;
			if (following_right_border) {
				if (distance<=distance_to_border-8) x_speed=-ENEMY_HSPEED;
				if (distance>=distance_to_border+8) x_speed=ENEMY_HSPEED;
			} else {
				if (distance<=distance_to_border-8) x_speed=ENEMY_HSPEED;
				if (distance>=distance_to_border+8) x_speed=-ENEMY_HSPEED;
			} /* if */ 
		} /* if */ 

		{
			CObject *o=0;

			o=game->object_collision(0,0,this,CONSTITUTION_SOLID);
			if (o!=0 && o->constitution_test(CONSTITUTION_CAR)) {
				CObject *o=new CExplosionObject(x-16,y-32,&game->explosion_tiles,0,11,game);
				game->objects.Add(o);
				return false;
			} else {
				/* Car collision: */ 
				o=game->object_collision(0,0,this,CONSTITUTION_CAR);
				if (o!=0) {
					CCarObject *co=(CCarObject *)o;

					co->car_collision(this);
					car_collision(co);
				} /* if */ 
			} /* if */ 
		}
	} else {
		y_speed=0;
	} /* if */ 

	if (game->min_distance_to_players(y)>PLAYING_WINDOW) return false;
	
	return true;
} /* CEnemyCarObject::cycle */ 

