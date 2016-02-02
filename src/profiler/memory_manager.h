//--------------------------------------------------------------------------
// Copyright (C) 2015-2016 Cisco and/or its affiliates. All rights reserved.
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

// memory_manager.h author Joel Cornett <jocornet@cisco.com>

#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "main/thread.h"

struct CombinedMemoryStats;

class Memory
{
public:
    static void set_runtime(bool yesno)
    { is_runtime = yesno; }

    static bool runtime()
    { return is_runtime; }

    // global accumulated stats
    static const CombinedMemoryStats& get_fallthrough_stats();

    // thread local call
    static void consolidate_fallthrough_stats();

private:
    static THREAD_LOCAL bool is_runtime;
};

struct RuntimeContext
{
    RuntimeContext()
    { Memory::set_runtime(true); }

    ~RuntimeContext()
    { Memory::set_runtime(false); }
};

#endif
