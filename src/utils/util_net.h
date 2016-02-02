//--------------------------------------------------------------------------
// Copyright (C) 2014-2016 Cisco and/or its affiliates. All rights reserved.
// Copyright (C) 2003-2013 Sourcefire, Inc.
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
// util_net.h author Chris Green <cmg@sourcefire.com>

#ifndef UTIL_NET_H
#define UTIL_NET_H

// Miscellaneous "to string" functions.
// Both functions return pointers to static buffers.
// Be aware that subsequent calls will overwrite the memory that is pointed to

#include "main/snort_types.h"
#include "sfip/sfip_t.h"

SO_PUBLIC char* inet_ntoax(const sfip_t*);

#endif

