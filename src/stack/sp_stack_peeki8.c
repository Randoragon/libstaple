/*  Staple - A general-purpose data structure library in pure C89.
 *  Copyright (C) 2021  Randoragon
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation;
 *  version 2.1 of the License.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#include "../sp_stack.h"
#include "../internal.h"
#include <stdint.h>
#include <inttypes.h>

int8_t sp_stack_peeki8(const struct sp_stack *stack)
{
#ifdef STAPLE_DEBUG
	if (stack == NULL) {
		error(("stack is NULL"));
		return 0;
	}
	if (stack->elem_size != sizeof(int8_t)) {
		error(("stack->elem_size is incompatible with elem type (%lu != %lu)",
					(unsigned long)stack->elem_size, sizeof(int8_t)));
		return 0;
	}
	if (stack->size == 0) {
		error(("stack is empty"));
		return 0;
	}
#endif
	return ((int8_t*)stack->data)[stack->size - 1];
}

#else
typedef int prevent_empty_translation_unit;
#endif
