//--------------------------------------------------------------------------
// Copyright (C) 2014-2016 Cisco and/or its affiliates. All rights reserved.
// Copyright (C) 2005-2013 Sourcefire, Inc.
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

#include "port_var_table.h"

//-------------------------------------------------------------------------
// PortVarTable
//-------------------------------------------------------------------------

/*
*  Create a PortVar Table
*
*  The PortVar table used to store and lookup Named PortObjects
*/
PortVarTable* PortVarTableCreate(void)
{
    PortObject* po;
    SFGHASH* h;

    /*
     * This is used during parsing of config,
     * so 1000 entries is ok, worst that happens is somewhat slower
     * config/rule processing.
     */
    h = sfghash_new(1000,0,0,PortObjectFree);
    if ( !h )
        return 0;

    /* Create default port objects */
    po = PortObjectNew();
    if ( !po )
        return 0;

    /* Default has an ANY port */
    PortObjectAddPortAny(po);

    /* Add ANY to the table */
    PortVarTableAdd(h, po);

    return h;
}

/*
    This deletes the table, the PortObjects and PortObjectItems,
    and rule list.
*/
int PortVarTableFree(PortVarTable* pvt)
{
    if ( pvt )
    {
        sfghash_delete(pvt);
    }
    return 0;
}

/*
*   PortVarTableAdd()
*
*   returns
*       -1 : error, no memory...
*        0 : added
*        1 : in table
*/
int PortVarTableAdd(PortVarTable* h, PortObject* po)
{
    int stat;
    stat = sfghash_add(h,po->name,po);
    if ( stat == SFGHASH_INTABLE )
        return 1;
    if ( stat == SFGHASH_OK )
        return 0;
    return -1;
}

PortObject* PortVarTableFind(PortVarTable* h, const char* name)
{
    if (!h || !name)
        return NULL;

    return (PortObject*)sfghash_find(h,name);
}

