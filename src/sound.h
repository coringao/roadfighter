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

#ifndef __BRAIN_SDL_SOUND
#define __BRAIN_SDL_SOUND

typedef Mix_Chunk * SOUNDT;

bool Sound_initialization(void);
int Sound_initialization(int nc,int nrc);
void Sound_release(void);

bool Sound_file_test(char *f1);

SOUNDT Sound_create_sound(char *file);
void Sound_delete_sound(SOUNDT s);
int Sound_play(SOUNDT s);
int Sound_play(SOUNDT s,int volume);
int Sound_play_continuous(SOUNDT s);
int Sound_play_continuous(SOUNDT s,int volume);
void Sound_play_ch(SOUNDT s,int channel);
void Sound_play_ch(SOUNDT s,int channel,int volume);

void Sound_create_music(char *f1,int times);
void Sound_release_music(void);
void Sound_pause_music(void);
void Sound_unpause_music(void);

void Sound_music_volume(int volume);

/* These functions are AGRESIVE! (i.e. they actually STOP SDL_mixer and restart it) */
void Stop_playback(void);
void Resume_playback(void);
int Resume_playback(int nc,int nr);

#endif

