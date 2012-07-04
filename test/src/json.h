#ifndef _HJSON__H
#define _HJSON__H

/* cJSON Types: */
#define cJSON_False 0
#define cJSON_True 1
#define cJSON_NULL 2
#define cJSON_Number 3
#define cJSON_String 4
#define cJSON_Array 5
#define cJSON_Object 6
	
#define cJSON_IsReference 256


/* The cJSON structure: */
typedef struct _hJSON{
	struct _hJSON *next,*prev;	/* next/prev allow you to walk array/object chains. Alternatively, use GetArraySize/GetArrayItem/GetObjectItem */
	struct _hJSON *child;		/* An array or object item will have a child pointer pointing to a chain of the items in the array/object. */
	int type;					/* The type of the item, as above. */

	char *valuestring;			/* The item's string, if type==cJSON_String */
	long long valueint;				/* The item's number, if type==cJSON_Number */
	double valuedouble;			/* The item's number, if type==cJSON_Number */

	char *string;				/* The item's name string, if this item is the child of, or is in the list of subitems of an object. */
} hJSON;




/* Supply a block of JSON, and this returns a cJSON object you can interrogate. Call cJSON_Delete when finished. */
extern hJSON *hJSON_Parse(const char *value);

/* Delete a cJSON entity and all subentities. */
extern void   hJSON_Delete(hJSON *c);

/* Returns the number of items in an array (or object). */
extern int	  HJSON_ArrSize(hJSON *array);
/* Retrieve item number "item" from array "array". Returns NULL if unsuccessful. */
extern hJSON *HJSON_GetArrayNode(hJSON *array,int item);
/* Get item "string" from object. Case insensitive. */
extern hJSON *HJSON_GetNodeL1(hJSON *object,const char *string);

/* For analysing failed parses. This returns a pointer to the parse error. You'll probably need to look a few chars back to make sense of it. Defined when cJSON_Parse() returns 0. 0 when cJSON_Parse() succeeds. */
extern const char *hJSON_GetErrorPtr(void);
	
#endif

