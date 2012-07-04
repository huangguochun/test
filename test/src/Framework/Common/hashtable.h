#ifndef HASHTBL_H
#define HASHTBL_H

struct hashnode_s {
	void *pv_key;
	void *pv_data;
	struct hashnode_s *p_next;
};

typedef struct _HashTable{
	int i_capacity;
	int i_size;
	struct hashnode_s *nodes[50];
} HashTable;

HashTable *hashtable_new(int size);

void hashtable_delete(HashTable *p_tbl);

int hashtable_insert_entity(HashTable *p_tbl, void *pv_key, void *pv_data);

int hashtable_remove_entity(HashTable *p_tbl, void *pv_key);

void *hashtable_get(HashTable *p_tbl, void *pv_key);

void hashtable_clear(HashTable *p_tbl);


#define  hashtable_for_each_begin(p_tbl,i_idx,p_node)		\
	for (i_idx = 0; i_idx < p_tbl->i_capacity; ++ i_idx) {		\
		p_node = p_tbl->nodes[i_idx];						\
		while(p_node) {									

#define hashtable_for_each_end(p_tbl,i_idx,p_node)			\
		p_node = p_node->p_next;							\
		}													\
	}

#endif