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

int sp_stack_printi(const struct sp_stack *stack)
{
	size_t i;
#ifdef STAPLE_DEBUG
	if (stack == NULL) {
		error(("stack is NULL"));
		return SP_EINVAL;
	}
	if (stack->elem_size != sizeof(int)) {
		error(("stack->elem_size is incompatible with elem type (%lu != %lu)",
					(unsigned long)stack->elem_size, sizeof(int)));
		return SP_EILLEGAL;
	}
#endif
	printf("sp_stack_printi()\nsize/capacity: %lu/%lu, elem_size: %lu\n",
		(unsigned long)stack->size, (unsigned long)stack->capacity, (unsigned long)stack->elem_size);
	for (i = stack->size; i-- > 0;) {
		const int elem = ((int*)stack->data)[i];
		printf("[%lu]\t""%d""\n", (unsigned long)stack->size - 1 - i, elem);
	}
	return 0;
}