/* Libvisual - The audio visualisation framework.
 * 
 * Copyright (C) 2004, 2005 Dennis Smit <ds@nerds-incorporated.org>
 *
 * Authors: Dennis Smit <ds@nerds-incorporated.org>
 *
 * $Id:
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef _LV_COLLECTION_H
#define _LV_COLLECTION_H

#include <libvisual/lv_common.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define VISUAL_COLLECTION(obj)				(VISUAL_CHECK_CAST ((obj), VisCollection))
#define VISUAL_COLLECTIONITER(obj)			(VISUAL_CHECK_CAST ((obj), VisCollectionIter))

typedef struct _VisCollection VisCollection;
typedef struct _VisCollectionIter VisCollectionIter;

/**
 * A VisCollection destroyer function needs this signature, these functions are used
 * to destroy data entries within collections.
 *
 * @arg data The data that was stored in a collection entry and thus can be destroyed.
 */
typedef void (*VisCollectionDestroyerFunc)(void *data);

/**
 */
typedef int (*VisCollectionDestroyFunc)(VisCollection *collection);

/**
 */
typedef int (*VisCollectionSizeFunc)(VisCollection *collection);

/**
 */
typedef VisCollectionIter *(*VisCollectionIterFunc)(VisCollection *collection);

/**
 */
typedef void *(*VisCollectionIterNextFunc)(VisCollectionIter *iter, VisCollection *collection, VisObject *context);

/**
 */
typedef int (*VisCollectionIterHasMoreFunc)(VisCollectionIter *iter, VisCollection *collection, VisObject *context);


/**
 */
struct _VisCollection {
	VisObject			 object;	/**< The VisObject data. */

	VisCollectionDestroyerFunc	 destroyer;
	VisCollectionDestroyFunc	 destroyfunc;
	VisCollectionSizeFunc		 sizefunc;
	VisCollectionIterFunc		 iterfunc;
};

/**
 */
struct _VisCollectionIter {
	VisObject			 object;

	VisCollectionIterNextFunc	 nextfunc;
	VisCollectionIterHasMoreFunc	 hasmorefunc;

	VisCollection			*collection;

	VisObject			*context;
};

/* prototypes */
int visual_collection_set_destroyer (VisCollection *collection, VisCollectionDestroyerFunc destroyer);
VisCollectionDestroyerFunc visual_collection_get_destroyer (VisCollection *collection);

int visual_collection_set_destroy_func (VisCollection *collection, VisCollectionDestroyFunc destroyfunc);
VisCollectionDestroyFunc visual_collection_get_destroy_func (VisCollection *collection);

int visual_collection_set_size_func (VisCollection *collection, VisCollectionSizeFunc sizefunc);
VisCollectionSizeFunc visual_collection_get_size_func (VisCollection *collection);

int visual_collection_set_iter_func (VisCollection *collection, VisCollectionIterFunc iterfunc);
VisCollectionIterFunc visual_collection_get_iter_func (VisCollection *collection);


int visual_collection_destroy (VisCollection *collection);
int visual_collection_size (VisCollection *collection);
VisCollectionIter *visual_collection_get_iter (VisCollection *collection);


VisCollectionIter *visual_collection_iter_new (VisCollectionIterNextFunc nextfunc,
		VisCollectionIterHasMoreFunc hasmorefunc, VisCollection *collection, VisObject *context);
int visual_collection_iter_init (VisCollectionIter *iter, VisCollectionIterNextFunc nextfunc,
		VisCollectionIterHasMoreFunc hasmorefunc, VisCollection *collection, VisObject *context);

void *visual_collection_iter_next (VisCollectionIter *iter);
int visual_collection_iter_has_more (VisCollectionIter *iter);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LV_COLLECTION_H */