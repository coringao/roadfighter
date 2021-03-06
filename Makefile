#####################################################################
# Copyright 2003-2009 Santi Ontanon (Brain Games)
# Work continued by 2017-2018 Carlos Donizete Froes [a.k.a coringao]
#
# This file is part of Road Fighter Remake.
# This is free software, licensed under the GPLv2 license.
#####################################################################

EXE = roadfighter
SRCDIR = src
OBJS = \
	$(SRCDIR)/sge/sge_blib.o		$(SRCDIR)/sge/sge_bm_text.o		\
	$(SRCDIR)/sge/sge_collision.o		$(SRCDIR)/sge/sge_misc.o		\
	$(SRCDIR)/sge/sge_primitives.o		$(SRCDIR)/sge/sge_rotation.o		\
	$(SRCDIR)/sge/sge_shape.o		$(SRCDIR)/sge/sge_surface.o		\
	$(SRCDIR)/sge/sge_textpp.o		$(SRCDIR)/sge/sge_tt_text.o		\
	$(SRCDIR)/CCarObject.o			$(SRCDIR)/CEnemyCarObject.o		\
	$(SRCDIR)/CEnemyFastCarObject.o		$(SRCDIR)/CEnemyNormalCarObject.o	\
	$(SRCDIR)/CEnemyRacerCarObject.o	$(SRCDIR)/CEnemySlidderCarObject.o	\
	$(SRCDIR)/CEnemyTruckObject.o		$(SRCDIR)/CExplosionObject.o		\
	$(SRCDIR)/CFuelObject.o			$(SRCDIR)/CGame.o			\
	$(SRCDIR)/CObject.o			$(SRCDIR)/CPlayerCarObject.o		\
	$(SRCDIR)/CRoadFighter.o		$(SRCDIR)/CSemaphoreObject.o		\
	$(SRCDIR)/CTile.o								\
	$(SRCDIR)/auxiliar.o			$(SRCDIR)/configuration.o		\
	$(SRCDIR)/debug.o			$(SRCDIR)/filehandling.o		\
	$(SRCDIR)/gameover_state.o		$(SRCDIR)/interlevel_state.o		\
	$(SRCDIR)/konami_state.o		$(SRCDIR)/loadmg2.o			\
	$(SRCDIR)/menu_state.o			$(SRCDIR)/playing_state.o		\
	$(SRCDIR)/presentation_state.o		$(SRCDIR)/quick_tables.o		\
	$(SRCDIR)/sound.o								\
	$(SRCDIR)/main.o

CXX = gcc
CXXFLAGS += -std=gnu++14 -g3 -O3 -fPIE -D_FORTIFY_SOURCE=2 `pkg-config --cflags sdl2`
LDFLAGS += -fPIE -pie -lm `pkg-config --libs sdl2` -lSDL2_image -lSDL2_mixer -lSDL2_ttf

RM = rm -rf
ECHO = echo
STRIP = strip

all: $(EXE)

%.o: %.cpp
	$(CXX) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

$(EXE): $(OBJS)
	$(CXX) $^ -o $@ $(LDFLAGS)
	@$(STRIP) $@
	@$(ECHO) "Compiled successfully and generated binary of the game"

clean:
	@$(RM) $(SRCDIR)/*.o $(SRCDIR)/sge/*.o $(SRCDIR)/*.bak core $(EXE)
	@$(ECHO) "Completed source cleanup"

.PHONY: all clean
