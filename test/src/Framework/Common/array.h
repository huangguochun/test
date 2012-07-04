#ifndef ARRAY_H
#define ARRAY_H

#define ARRAY_HEAD_SIZE 10


/*linear storage structure of variable array*/
typedef struct _Array {
    int i_size;		/*elements size in the array*/
    int i_capacity;	/*the capacity of the array*/
    void * data[ARRAY_HEAD_SIZE + 1]; /*store the actual data*/
    void (*destroy)(void *);		/*the destructor function for data*/
} Array;

#define array_extra(a, i)  (((void **)(a)->data[ARRAY_HEAD_SIZE])[i - ARRAY_HEAD_SIZE])

#define array_at(a, i) (i < ARRAY_HEAD_SIZE ? (a)->data[i] : array_extra(a, i))

#define array_pos(a, i) (i < ARRAY_HEAD_SIZE ? &(a)->data[i] : &array_extra(a, i))

/************************************************************************
* Init a Array.
* @param destroy: destructor function, it can be NULL
************************************************************************/
void array_init(Array *, void (*destroy)(void *));

/************************************************************************
* New a Array.
* @param destroy: destructor function, it can be NULL
************************************************************************/
Array * array_new(void (*destroy)(void *));

/************************************************************************
* Add a value at the end of the array
* @param destroy: destructor function
************************************************************************/
void array_add(Array *, void *p_value);

/************************************************************************
* Insert a value at the special position
* @param i_idx : special position, 
************************************************************************/
void array_insert(Array *, int i_idx, void *p_value);

/************************************************************************
* Get the p_value's index, if not find return -1
************************************************************************/
int array_index_of(Array *, void *p_value);

/************************************************************************
* Get the value at special position, if not find return NULL
************************************************************************/
void * array_value_of(Array *, int);

/************************************************************************
* Take down the value at special position, but not free the value
************************************************************************/
void * array_take_down_at(Array *, int);

/************************************************************************
* Take down the special value, but not free the value
************************************************************************/
void * array_take_down_value(Array *, void *);

/************************************************************************
* Take down the value at special position, and call Array's destroy function
************************************************************************/
void array_remove_at(Array *, int);

/************************************************************************
* Take down the special value, and call Array's destroy function
************************************************************************/
void array_remove_value(Array *, void *);

/************************************************************************
* Clear all values, and call Array's destroy function
************************************************************************/
void array_clear(Array *);

/************************************************************************
* Delete the array, and clear it's values
************************************************************************/
void array_delete(Array *);

/************************************************************************
* Regulate the capacity to its best size
************************************************************************/
void array_regulate_capacity(Array *);


#endif
