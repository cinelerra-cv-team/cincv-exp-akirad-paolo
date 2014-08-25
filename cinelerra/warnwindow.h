
/*
 * CINELERRA warning window based on tooltip window code
 * Copyright (C) 2008 Adam Williams <broadcast at earthling dot net>
 * Copyright (C) 2014 Paolo Rampino <akir4d at gmail dot com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * 
 */

#ifndef WARNWINDOW_H
#define WARNWINDOW_H

#include "bcdialog.h"
#include "guicast.h"
#include "mwindow.inc"
#include "warnwindow.inc"



// Warning initialization


class WarnWindow : public BC_DialogThread
{
friend class WarnWindowGui;
public:
	WarnWindow(MWindow *mwindow, char *set_warn, int slotn);

	BC_Window* new_gui();
	MWindow *mwindow;
	WarnWindowGUI *gui;
private:
	char* s_warn;
	int nslot;
};


class WarnWindowGUI : public BC_Window
{
public:
	WarnWindowGUI(MWindow *mwindow,
		WarnWindow *thread,
		int x,
		int y,
		char* s_warn,
		int nslot);
	void create_objects();
	int keypress_event();
	MWindow *mwindow;
	WarnWindow *thread;
	BC_Title *warn_text;
private:
	char *get_warn;
	int slotn;
};

class WarnDisable : public BC_CheckBox
{
public:
	WarnDisable(MWindow *mwindow, WarnWindowGUI *gui, int x, int y, int nslot);
	int handle_event();
	WarnWindowGUI *gui;
	MWindow *mwindow;
	int nslot;
};

class WarnClose : public BC_Button
{
public:
	WarnClose(MWindow *mwindow, WarnWindowGUI *gui, int x, int y);
	int handle_event();
	static int calculate_w(MWindow *mwindow);
	static int calculate_h(MWindow *mwindow);
	WarnWindowGUI *gui;
	MWindow *mwindow;
};



#endif
