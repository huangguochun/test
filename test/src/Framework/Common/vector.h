#ifndef _VECTOR_H
#define  _VECTOR_H

typedef struct _VectorNode {
	struct _VectorNode *p_prev;
	struct _VectorNode *p_next;
	void *pv_data;
} VectorNode;

typedef struct _Vector {
	VectorNode head;
	int i_size;
	void (*destroy)(void *);
}Vector;

/************************************************************************
* constructor and de-constructor
************************************************************************/
Vector *vector_new( void (*destroy)(void *) );

void vector_init(Vector *p_vec, void (*destroy)(void *) );

void vector_delete(Vector *p_vec);

VectorNode *vector_node_new(void *pv_data);

/************************************************************************
* method
************************************************************************/

void vector_append_node(Vector *p_vec, VectorNode *p_node);

VectorNode * vector_append_data(Vector *p_vec, void *pv_data);

void vector_insert_node(Vector *p_vec, VectorNode *p_pos, VectorNode *p_node);

VectorNode * vector_insert_data(Vector *p_vec, int i_pos, void *pv_data);

void vector_take_down(Vector *p_vec, VectorNode *p_node);

void vector_remove_node(Vector *p_vec, VectorNode *p_node);

void vector_remove_data(Vector *p_vec, void *pv_data);

int vector_index_of(Vector *p_vec, void *pv_data);

VectorNode * vector_node_of(Vector *p_vec, void *pv_data);

VectorNode *vector_node_at(Vector *p_vec, int i_pos);

void vector_clear(Vector *p_vec);


#define vector_for_each(p_pos, p_vec) \
	for (p_pos = p_vec->head.p_next; p_pos != &p_vec->head; p_pos = p_pos->p_next)

#define vector_for_each_reverse(p_pos, p_vec) \
	for (p_pos = p_vec->head.p_prev; p_pos != &p_vec->head; p_pos = p_pos->p_prev)

#define vector_for_each_safe(p_pos, n, p_vec) \
	for (p_pos = p_vec->head.p_next, n = p_pos->p_next; p_pos != &p_vec->head; p_pos = n, n = p_pos->p_next)

#define vector_for_each_safe_reverse(p_pos, n, p_vec) \
	for (p_pos = p_vec->head.p_prev, n = p_pos->p_prev; p_pos != &p_vec->head; p_pos = n, n = p_pos->p_prev)

#define  vector_node_init(p_node) \
	(p_node)->p_next = (p_node)->p_prev = (p_node)

#endif