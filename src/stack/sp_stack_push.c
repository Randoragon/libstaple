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
#include "../sp_stack.h"
#include "../internal.h"
#include "../sp_errcodes.h"
#include <string.h>

int sp_stack_push(struct sp_stack *stack, const void *elem)
{
#ifdef STAPLE_DEBUG
	if (stack == NULL) {
		error(("stack is NULL"));
		return SP_EINVAL;
	}
	if (elem == NULL) {
		error(("elem is NULL"));
		return SP_EINVAL;
	}
#endif
	if (sp_size_try_add(stack->size * stack->elem_size, stack->elem_size))
		return SP_ERANGE;
	if (sp_buf_fit(&stack->data, stack->size, &stack->capacity, stack->elem_size))
		return SP_ENOMEM;
	memcpy((char*)stack->data + stack->size++ * stack->elem_size, elem, stack->elem_size);
	return 0;
}
