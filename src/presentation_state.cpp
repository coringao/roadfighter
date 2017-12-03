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

#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

#include "sound.h"

#include "CTile.h"
#include "CObject.h"
#include "CGame.h"
#include "CRoadFighter.h"
#include "auxiliar.h"

const int presentation_fade_time=25;

int CRoadFighter::presentation_cycle(void)
{
	int i;
	bool key_pressed;

	if (state_timmer==0) {
		presentation_state=0;
		presentation_timmer=0;
	} /* if */ 

	if (presentation_state==0) presentation_timmer++;
	if (presentation_state==1) presentation_timmer--;
	if (presentation_state==2) presentation_timmer++;
	if (presentation_state==3) presentation_timmer--;

	key_pressed=false;
	if (state_timmer>=5) {
		for(i=0;i<SDLK_LAST;i++) {
			if (keyboard[i] && !old_keyboard[i]) key_pressed=true;
		} /* for */ 
	} /* if */ 

	if (presentation_state==0 && 
		(state_timmer>=350 || key_pressed)) {
		presentation_state=1;
		if (presentation_timmer>presentation_fade_time) presentation_timmer=presentation_fade_time;
	} /* if */ 
	if (presentation_state==2 && 
		(state_timmer>=700 || key_pressed)) {
		presentation_state=3;
		if (presentation_timmer>presentation_fade_time) presentation_timmer=presentation_fade_time;
	} /* if */ 

	if (presentation_state==1 && presentation_timmer<=0) presentation_state=2;
	if (presentation_state==3 && presentation_timmer<=0) return KONAMI_STATE;

	return PRESENTATION_STATE;
} /* CRoadFighter::presentation_cycle */ 



void CRoadFighter::presentation_draw(SDL_Surface *screen)
{
	if (presentation_state<2) SDL_BlitSurface(disclaimer_sfc,0,screen,0);
						 else SDL_BlitSurface(retroremakes_sfc,0,screen,0);

	{
		float f=float(presentation_timmer)*(1.0F/float(presentation_fade_time));
		if (f<0.0) f=0.0;
		if (f<1.0) surface_fader(screen,f,f,f,0);
	} /* if */ 

} /* CRoadFighter::presentation_draw */ 
