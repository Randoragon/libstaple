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
#include "../sp_queue.h"
#include "../internal.h"
#include "../sp_errcodes.h"

int sp_queue_printsc(const struct sp_queue *queue)
{
	size_t i;
#ifdef STAPLE_DEBUG
	if (queue == NULL) {
		error(("queue is NULL"));
		return SP_EINVAL;
	}
	if (queue->elem_size != sizeof(signed char)) {
		error(("queue->elem_size is incompatible with elem type (%lu != %lu)",
					(unsigned long)queue->elem_size, sizeof(signed char)));
		return SP_EILLEGAL;
	}
#endif
	printf("sp_queue_printsc()\nsize/capacity: "SP_SIZE_FMT"/"SP_SIZE_FMT", elem_size: "SP_SIZE_FMT"\n",
		(SP_SIZE_T)queue->size, (SP_SIZE_T)queue->capacity, (SP_SIZE_T)queue->elem_size);
	for (i = 0; i < queue->size; i++) {
		const signed char elem = *(signed char*)sp_ringbuf_get(i, queue->data, queue->capacity, queue->elem_size, queue->head);
		printf("["SP_SIZE_FMT"]\t""%hd\t'%c'""\n", (SP_SIZE_T)i, elem, elem);
	}
	return 0;
}
