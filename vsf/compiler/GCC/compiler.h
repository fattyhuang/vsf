/***************************************************************************
 *   Copyright (C) 2009 - 2010 by Simon Qian <SimonQian@SimonQian.com>     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef __COMPILER_H_INCLUDED__
#define __COMPILER_H_INCLUDED__

#include <string.h>

#define ROOTFUNC	
#define PACKED_HEAD	
#define PACKED_MID	__attribute__ ((packed))
#define PACKED_TAIL	
#define WEAKFUNC        // TODO

#define vsf_gint_t						int// TODO
#define vsf_set_gint(gint)				// TODO
#define vsf_get_gint()					0// TODO
#define vsf_enter_critical()			// TODO
#define vsf_leave_critical()			// TODO

#define compiler_get_heap()             NULL    // TODO
#define compiler_get_heap_size()        1024    // TODO

#define compiler_set_pc(reg)			// TODO
#define compiler_get_lr(reg)			// TODO

#endif	// __COMPILER_H_INCLUDED__
