//--------------------------------------------------------------------------
// Copyright (C) 2014-2016 Cisco and/or its affiliates. All rights reserved.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License Version 2 as published
// by the Free Software Foundation.  You may not use, modify or distribute
// this program under any other version of the GNU General Public License.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//--------------------------------------------------------------------------

// main.cc author Russ Combs <rucombs@cisco.com>

#ifndef MAIN_H
#define MAIN_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

struct lua_State;

const char* get_prompt();

// commands provided by the snort module
int main_dump_stats(lua_State* = nullptr);
int main_rotate_stats(lua_State* = nullptr);
int main_reload_config(lua_State* = nullptr);
int main_reload_hosts(lua_State* = nullptr);
int main_process(lua_State* = nullptr);
int main_pause(lua_State* = nullptr);
int main_resume(lua_State* = nullptr);
int main_quit(lua_State* = nullptr);
int main_help(lua_State* = nullptr);

#ifdef BUILD_SHELL
int main_dump_plugins(lua_State* = nullptr);
int main_detach(lua_State* = nullptr);
#endif

#endif

