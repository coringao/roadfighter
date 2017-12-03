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

#include "CTile.h"
#include "CObject.h"

CCarObject::CCarObject(void) : CObject()
{
	last_collision=0;
} /* CCarObject::CCarObject */ 


CCarObject::CCarObject(int nx,int ny,CTile *t,CGame *g) : CObject(nx,ny,t,CONSTITUTION_CAR,g)
{
	y_speed=0;
	y_precision=0;

	state=0;

	x_speed=0;
	x_precision=0;

	last_collision=0;
} /* CCarObject::CCarObject */ 


CCarObject::~CCarObject(void)
{
} /* CCarObject::~CCarObject */ 



bool CCarObject::cycle(unsigned char *keyboard,unsigned char *old_keyboard)
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
	return true;
} /* CCarObject::CCarObject */ 


void CCarObject::car_collision(CCarObject *car)
{
	last_collision=car;
} /* CCarObject::car_collision */ 


long int CCarObject::compute_next_x(void)
{
	long int tmp=x_precision+x_speed;
	long int new_x=x;

	while(tmp>(1<<8)) {
		new_x++;
		tmp-=1<<8;
	} /* while */ 
	while(tmp<(1<<8)) {
		new_x--;
		tmp+=1<<8;
	} /* while */ 

	return new_x;
} /* CCarObject::compute_next_y */ 


long int CCarObject::compute_next_y(void)
{
	long int tmp=y_precision+y_speed;
	long int new_y=y;

	while(tmp>(1<<8)) {
		new_y++;
		tmp-=1<<8;
	} /* while */ 
	while(tmp<(1<<8)) {
		new_y--;
		tmp+=1<<8;
	} /* while */ 

	return new_y;
} /* CCarObject::compute_next_y */ 

