#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

/*** Types ********************************************************************/

# define TRUE 1
# define FALSE 0

typedef int						(*t_comparator)(void *, void *);
typedef int						(*t_bipredicate)(void *, void *);
typedef void*					(*t_bifunction)(void *, void *);
typedef void					(*t_biconsumer)(void *, void *);
typedef int						(*t_predicate)(void *);
typedef void*					(*t_function)(void *);
typedef void					(*t_consumer)(void *);
typedef void*					(*t_supplier)();
typedef t_biconsumer			t_bicon;
typedef t_bifunction			t_bifun;
typedef t_bipredicate			t_bipre;
typedef t_supplier				t_sup;
typedef t_function				t_fun;
typedef t_consumer				t_con;
typedef t_comparator			t_com;
typedef t_predicate				t_pre;

typedef unsigned long long		t_uint64;
typedef unsigned int			t_uint32;
typedef unsigned short			t_uint16;
typedef unsigned char			t_uint8;

typedef unsigned long			t_ulong;

typedef struct s_iterator		t_iterator;
typedef struct s_citerator		t_citerator;

typedef struct s_bmpfileheader	t_bmpfileheader;
typedef struct s_bmpinfoheader	t_bmpinfoheader;
typedef struct s_bmpheader		t_bmpheader;
typedef struct s_bitmap			t_bitmap;

typedef struct s_dentry			t_dentry;
typedef struct s_dlist			t_dlist;

typedef struct s_centry			t_centry;
typedef struct s_entry			t_entry;
typedef struct s_clist			t_clist;
typedef struct s_list			t_list;

typedef struct s_mapentry		t_mapentry;
typedef struct s_map			t_map;

typedef struct s_color			t_color;

/*** BMP Image utils **********************************************************/

struct s_bmpfileheader
{
	char	signature[2];
	int		filesize;
	int		reserved;
	int		data_offset;
} __attribute__((__packed__));

struct s_bmpinfoheader
{
	int		dibheadersize;
	int		width;
	int		height;
	short	planes;
	short	bitsperpixel;
	int		compression;
	int		imagesize;
	int		ypixelpermeter;
	int		xpixelpermeter;
	int		numcolorspallette;
	int		mostimpcolor;
} __attribute__((__packed__));

struct s_bmpheader
{
	t_bmpfileheader	file;
	t_bmpinfoheader	infos;
} __attribute__((__packed__));

struct s_bitmap
{
	t_bmpheader	header;
	char		*body;
};

void		bmp_set_pixel(t_bitmap *bitmap, int x, int y, t_color color);
t_color		bmp_get_pixel(t_bitmap *bitmap, int x, int y);
int			bmp_save(char *output, t_bitmap *bitmap);
ssize_t		bmp_write(int fd, t_bitmap *bitmap);
t_bitmap	*bmp_init(int width, int height);
void		bmp_free(t_bitmap *image);

/*** Advanced string implementation *******************************************/

/**
 * @brief Create a new string from a string (char *).
 * 
 * @param str the base string (char *)
 * @return the new string
 */
char		**as_string(char *str);
/**
 * @brief Create a new string.
 * 
 * @return the new string, or NULL in case of error.
 */
char		**str_new(void);
/**
 * @brief Append a string (char *) to the begenning of the string.
 * 
 * @param container the string
 * @param str the string (char *) to append
 * @return the same container, for chaining, or NULL in case of error.
 */
char		**str_prepend(char **container, char *str);
/**
 * @brief Append a string (char *) to the end of the string.
 * 
 * @param container the string
 * @param str the string (char *) to append
 * @return the same container, for chaining, or NULL in case of error.
 */
char		**str_append(char **container, char *str);
/**
 * @brief Append a char to the begenning of the string.
 * 
 * @param container the string
 * @param c char to append
 * @return the same container, for chaining, or NULL in case of error.
 */
char		**str_cappend(char **container, char c);
/**
 * @brief Remove last element of the string
 * 
 * @param container the string
 * @return the same container, with, at least one element, or NULL if error.
 */
char		**str_rmlast(char **container);
/**
 * @brief Insert a string (char *) to a specific index of the string.
 * 
 * @param container the string
 * @param str the string (char *) to insert
 * @param index the index at which the string (char *) will be inserted
 * (equivalent to prepend if less or equal to 0, equivalent to append if too
 * long).
 * @return the same container, for chaining, or NULL in case of error.
 */
// char		**str_insert(char **container, char *str, int index);

/*** String utils *************************************************************/

/**
 * @brief Copies the content of src + start into dest without the
 * null-terminating \0, and stops copying if the end of dest (\0) is
 * encountered.
 * 
 * @param dest the buffer for the result
 * @param src the string to copy
 * @param start the index at witch the copy will start in src
 * @param max the maximum amount of characters to copy (-1 to copy all)
 * @return the destination
 */
char		*ft_strninsert(char *dest, const char *src, size_t start,
				size_t max);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
/**
 * @brief Copies the content of src + start into dest without the
 * null-terminating \0, and stops copying if the end of dest (\0) is
 * encountered.
 * 
 * @param dest the buffer for the result
 * @param src the string to copy
 * @param start the index at witch the copy will start in src
 * @return the destination
 */
char		*ft_strinsert(char *dest, const char *src, size_t start);
size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dest, const char *src, size_t dstsize);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strtrim(const char *s1, const char *set);
/**
 * @brief Join two strings together, or duplicate one of them if the other is
 * NULL.
 * 
 * @param s1 the first string
 * @param s2 the second string
 * @return the result of the operation, or NULL if allocation fails or if s1 and
 * s2 are NULL too;
 */
char		*ft_strjoin(const char *s1, const char *s2);
/**
 * @brief Check if a string starts by a prefix
 * 
 * @param string the string to test
 * @param prefix the prefix to test
 * @return if string starts by prefix (FALSE if string or prefix is NULL)
 */
int			ft_starts_with(char *string, char *prefix);
/**
 * @brief Check if a string ends by a suffix
 * 
 * @param string the string to test
 * @param suffix the suffix to test
 * @return if string ends by suffix (FALSE if string or suffix is NULL)
 */
int			ft_ends_with(char *string, char *suffix);
/**
 * @brief Copy a string from a location to another
 * 
 * @param dest the buffer for src
 * @param src the string to copy
 * @return dest
 */
char		*ft_strcpy(char *dest, const char *src);
/**
 * @brief Count the number of occurences of the character c in the string str.
 * 
 * @param str The string
 * @param c The char to find
 * @return the number of occurences
 */
int			ft_strcnt(const char *str, char c);
/**
 * @brief Get the first index of a character in a string.
 * 
 * @param str the string
 * @param c the character to find
 * @return the index of the first occurence of c in str, or -1 if not found.
 */
int			ft_strindex_of(char *str, char c);
char		*ft_strrchr(const char *s, int c);
/**
 * @brief Split the string each character separator into an array of strings.
 * 
 * @param string the string to split
 * @param separator the separator
 * @return char** an array of strings
 */
char		**ft_split(const char *string, char separator);
/**
 * @brief Search a character in a string and get a pointer to this location.
 * 
 * @param str the string
 * @param c the character to find
 * @return the pointer at the character's location, or NULL if not found.
 */
char		*ft_strchr(const char *str, int c);
/**
 * @brief Compare two strings and get the difference of the ascii values on the
 * first non-equal character. If one of the parameters is NULL, -1 is returned.
 * 
 * @param s1 the fitst string
 * @param s2 the second string
 * @return 0 if strings are equals, or the difference of the ascii values on the
 * first non-equal character else.
 */
int			ft_strcmp(char *s1, char *s2);
/**
 * @brief Split the string each character separator into an array of strings,
 * then free the base string.
 * 
 * @param string the string to split
 * @param separator the separator
 * @return char** an array of strings
 */
char		**ft_splitf(char *string, char separator);
/**
 * @brief Compare two strings and return TRUE if they are equals.
 * 
 * @param s1 the fitst string
 * @param s2 the second string
 * @return TRUE if they are equals
 */
int			ft_str_equals(char *s1, char *s2);
char		*ft_strdup(const char *s1);
char		*ft_strtoupper(char *str);
char		*ft_strtolower(char *str);
size_t		ft_strlen(const char *s);
int			str_not_empty(char *str);
int			str_is_empty(char *str);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isprint(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);

/*** Memory utils *************************************************************/

void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t len);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);

/*** Maps implementation ******************************************************/

struct s_mapentry
{
	t_mapentry	*next;
	void		*key;
	void		*value;
};

struct s_map
{
	t_biconsumer	del;
	t_mapentry		*first;
	int				size;
	t_bipredicate	identity_checker;
};

/**
 * @brief Create a new map, using identity_checker to get element.
 * 
 * @param identity_checker comparator for key values
 * @param del key and value destroyer
 * @return the new map
 */
t_map		*map_new(t_bipredicate identity_checker, t_biconsumer del);
/**
 * @brief Get a value of the map, using identity_checker to compare keys. Check
 * map_contains_key before to be sure of the result.
 * 
 * @param map the map
 * @param key the key of the value to get
 * @param value_container the container for resulting value
 * @return the value if found, else NULL
 */
void		*map_get(t_map *map, void *key);
/**
 * @brief Put a new entry in the map, and delete the old value if it already
 * exists.
 * 
 * @param map the map
 * @param key the key
 * @param value the value
 * @return TRUE if the operation succeeded, else FALSE
 */
int			map_put(t_map *map, void *key, void *value);
/**
 * @brief Change the value of the key if it already exists, else do nothing.
 * The old key will not be destroyed, so the del function will be called with
 * NULL as first parameter.
 * 
 * @param map the map
 * @param key the key
 * @param new_value the new value
 * @return TRUE if the operation succeeded, else FALSE
 */
int			map_replace(t_map *map, void *key, void *new_value);
/**
 * @brief Check if a key exists in the map.
 * 
 * @param map the map
 * @param key the key to test with identity_checker
 * @return TRUE if exists, else FALSE
 */
int			map_contains_key(t_map *map, void *key);
/**
 * @brief Remove an element from the map and return the value.
 * The old key will be destroyed, so the del function will be called with
 * NULL as second parameter.
 * 
 * @param map the map
 * @param map the key to delete
 * @return the removed value, or NULL if value not exists
 */
void		*map_remove(t_map *map, void *key);
/**
 * @brief Delete an element of the map.
 * 
 * @param map the map
 * @param map the key to delete
 * @return TRUE if the operation succeeded, else FALSE
 */
int			map_delete(t_map *map, void *key);
/**
 * @brief Clear the map and free all elements using map->del.
 * 
 * @param map the map to clear
 */
void		map_clear(t_map *map);
/**
 * @brief Free all the entries without freeing keys or values.
 * 
 * @param map the map to free
 */
void		map_free(t_map *map);
/**
 * @brief Clear and free the map.
 * 
 * @param map the map to destroy
 */
void		map_destroy(t_map *map);
/**
 * @brief Creates a shallow copy of an existing map
 * 
 * @param original the original map
 * @return the copy of the original map
 */
t_map		*map_copy(t_map *original);
/**
 * @brief Creates a deep copy of an existing map
 * 
 * @param original the original map
 * @param copy_elem the function that copies the content of key and value
 * @return the copy of the original map
 */
t_map		*map_clone(t_map *original, t_function copy_elem);
/**
 * @brief Sort the map using the comparator and return the result in a new map.
 * 
 * @param map the map
 * @param comparator the comparator, for example ft_strcmp to sort in ASCII
 * order.
 * @return the same map, for chaining
 */
t_map		*map_sort(t_map *map, t_comparator comparator);

/*** Double chained lists implementation **************************************/

struct s_dentry
{
	t_dentry	*previous;
	t_dentry	*next;
	void		*value;
};

struct s_dlist
{
	t_consumer	del;
	t_dentry	*first;
	int			size;
};

/**
 * @brief Creates a new double chained list
 * 
 * @param del the t_consumer used to delete properly an element
 * @return pointer to the created list, NULL if malloc error
 */
t_dlist		*dlst_new(t_consumer del);
/**
 * @brief Creates a new double chained list entry
 * 
 * @param value entry's value
 * @return pointer to the created entry, NULL if malloc error
 */
t_dentry	*dlst_new_entry(void *value);
/**
 * @brief Check if a list is not empty.
 * 
 * @param list the list
 * @return if the list is not empty
 */
int			dlst_not_empty(t_dlist *list);
/**
 * @brief Check if a list is empty.
 * 
 * @param list the list
 * @return if the list is empty
 */
int			dlst_is_empty(t_dlist *list);
void		dlst_free(t_dlist *list);
/**
 * @brief Clear and free all elements of the list with the del function.
 * 
 * @param list the list
 */
void		dlst_clear(t_dlist *list);
/**
 * @brief Clear (see lst_clear) and free the list.
 * 
 * @param list the list
 */
void		dlst_destroy(t_dlist *list);
/**
 * @brief Remove an element at the start of the list
 * 
 * @param list the list
 * @return pointer to the previous entry of the list
 */
t_dentry	*dlst_shift_entry(t_dlist *list);
/**
 * @brief Remove an element at the start of the list
 * 
 * @param list the list
 * @return the previous entry of the list
 */
void		*dlst_shift(t_dlist *list);
/**
 * @brief Insert an element at the start of the list.
 * 
 * @param list the list
 * @param element the element to insert
 * @return the new entry of the list
 */
void		*dlst_unshift(t_dlist *list, void *element);
/**
 * @brief Moves a pointer on a list element right
 * 
 * @param walk pointer on a list element
 * @return the pointer
 */
t_dentry	*dlst_walk_right(t_dentry *walk);
/**
 * @brief Moves a pointer on a list element left
 * 
 * @param walk pointer on a list element
 * @return the pointer
 */
t_dentry	*dlst_walk_left(t_dentry *walk);

/*** Lists implementation *****************************************************/

struct s_entry
{
	t_entry	*next;
	void	*value;
};

struct s_centry
{
	t_centry	*next;
};

struct s_list
{
	t_consumer	del;
	t_entry		*first;
	int			size;
};

struct s_clist
{
	t_consumer	del;
	t_centry	*first;
	int			size;
};

/**
 * @brief Reduce a list to a single element using an accumulator, then destroy
 * the list using lst_destroy.
 * 
 * @param list the list to reduce
 * @param id the initial value of the accumulator
 * @param accumulator the function that convert two elements into one
 * @param accumulator_free the function that be called at next iteration to free
 * the result of accumulator
 * @return the value of accumulator after the iteration
 */
void		*lst_reducef(t_list *list, void *id, t_bifunction accumulator,
				t_consumer accumulator_free);
/**
 * @brief Reduce a list to a single element using an accumulator.
 * 
 * @param list the list to reduce
 * @param id the initial value of the accumulator
 * @param accumulator the function that convert two elements into one
 * @param accumulator_free the function that be called at next iteration to free
 * the result of accumulator
 * @return the value of accumulator after the iteration
 */
void		*lst_reduce(t_list *list, void *id, t_bifunction accumulator,
				t_consumer accumulator_free);
/**
 * @brief Return the first element that pass the comparator
 * 
 * @param list the list
 * @param comparator the filter, first argument is the element to check.
 * @param arg the second argument for the comparator.
 * @return the element if found, NULL else
 */
void		*lst_find_first(t_list *list, t_bipredicate comparator, void *arg);
/**
 * @brief Tests is an item is in the list using comparator (or strict equality
 * is comparator is NULL)
 * 
 * @param list the list
 * @param item the item to find in the list
 * @param comparator the comparator
 * @return if the item is in the list
 */
int			lst_contains(t_list *list, void *item, t_comparator comparator);
/**
 * @brief Iterate over all elements of the list and execute the visitor with the
 * element and param as parameters.
 * 
 * @param list the list
 * @param filter function to execute
 */
void		lst_foreachp(t_list *list, t_biconsumer visitor, void *param);
/**
 * @brief Loop inside all values of the list and replace them with the result of
 * mapper.
 * 
 * @param list the list
 * @param mapper the function to execute on all the values of the list
 * @param del the function to delete an element of the list
 * @return t_list* the same list, for chaining
 */
t_list		*lst_map_in(t_list *list, t_function mapper, t_consumer del);
/**
 * @brief Remove a part of the list and return it in a new list and insert value
 * at the start index.
 * 
 * @param list the list
 * @param start the start index (start from the end if negative)
 * @param delete_count the number of elements to remove (only insert if 0)
 * @param value the value to insert (nullable)
 * @return the list containing the elements (not null even if delete count is 0)
 */
t_list		*lst_splice(t_list *list, int start, int delete_count, void *value);
/**
 * @brief Loop inside all values of the list and replace them in a new list with
 * the result of mapper.
 * 
 * @param list the list
 * @param mapper the function to execute on all the values of the list
 * @param del the function to delete an element of the list
 * @return the new list
 */
t_list		*lst_map(t_list *list, t_function mapper, t_consumer del);
/**
 * @brief Replace an element at index
 * 
 * @param list the list
 * @param index the index of the element to replace. If index is greater than 
 * (list.size - 1), the last element is replaced.
 * @param new_value the new value of the index
 * @return void* the old element, NULL in case of error
 */
void		*lst_set(t_list *list, int index, void *new_value);
/**
 * @brief Insert an element at a given index of the list.
 * 
 * @param list the list
 * @param index the index at which the element will be inserted
 * @param element the element to insert
 * @return the new size of list
 */
int			lst_insert(t_list *list, int index, void *value);
/**
 * @brief Loop inside all values of the list and remove them if the predicate
 * filter returns false.
 * 
 * @param list the list
 * @param filter the filter
 * @return t_list* the same list, for chaining
 */
t_list		*lst_filter_in(t_list *list, t_predicate filter);
/**
 * @brief Copies all elements of the list in a new list if they pass the filter.
 * 
 * @param list the list
 * @param filter the filter
 * @return the new list
 */
t_list		*lst_filter(t_list *list, t_predicate filter);
/**
 * @brief Iterate over all elements of the list and execute the visitor with the
 * element as parameter.
 * 
 * @param list the list
 * @param filter function to execute
 */
void		lst_foreach(t_list *list, t_consumer visitor);
/**
 * @brief Add all the element of a list into another.
 * 
 * @param container the container
 * @param list the list to copy at the end of contanter
 * @return the new size of container
 */
int			lst_add_all(t_list *container, t_list *list);
/**
 * @brief Remove all elements of the list in range [min;max[.
 * 
 * @param list the list
 * @param min the index (included) of the first element to remove, starts from 
 * the end if negative
 * @param max the index (excluded) of the last element to remove, starts from 
 * the end if negative
 * @return the new list
 */
t_list		*lst_slice(t_list *list, int start, int end);
/**
 * @brief Insert an element at the start of the list.
 * If the push operation fails, element is free using list->del.
 * 
 * @param list the list
 * @param element the element to insert
 * @return the element if success, NULL otherwise
 */
void		*lst_unshift(t_list *list, void *element);
/**
 * @brief Convert the void** array into a new t_list, then free array.
 * 
 * @param array the array to convert
 * @param del the function to free an element of the list
 * @return the new list
 */
t_list		*as_listf(void **array, t_consumer del);
/**
 * @brief Get an entry at a given position
 * 
 * @param list the list
 * @param index the index of the entry
 * @return the entry, or null if out of bounds
 * 
 * @deprecated avoid usage of entries outside the libft
 */
t_entry		*lst_get_entry(t_list *list, int index);
/**
 * @brief Convert the void** array into a new t_list.
 * 
 * @param array the array to convert
 * @param del the function to free an element of the list
 * @return the new list
 */
t_list		*as_list(void **array, t_consumer del);
/**
 * @brief Append an element at the end of the list.
 * If the push operation fails, element is free using list->del.
 * 
 * @param list the custom list
 * @param element the element to add
 * @return the pushed element if success, NULL otherwise
 */
void		*lst_push(t_list *list, void *element);
/**
 * @brief Remove the element index from the list and return it.
 * 
 * @param list the list
 * @param index the index of the element to remove
 * @return the element removed from the list, or NULL if index is invalid
 */
void		*lst_remove(t_list *list, int index);
/**
 * @brief Concatenate the given lists into a new one.
 * 
 * @param t1 the first list
 * @param t2 the first list
 * @return the new list
 */
t_list		*lst_concat(t_list *t1, t_list *t2);
/**
 * @brief Remove the element index from the list and delete it.
 * 
 * @param list the list
 * @param index the index of the element to delete
 * @return TRUE if the operation was successful, FALSE otherwise
 */
void		lst_delete(t_list *list, int index);
void		*lst_get(t_list *list, int index);
t_entry		*lst_shift_entry(t_list *list);
t_entry		*lst_last_entry(t_list *list);
t_entry		*lst_new_entry(void *value);
/**
 * @brief Check if a list is not empty.
 * 
 * @param list the list
 * @return if the list is not empty
 */
int			lst_not_empty(t_list *list);
/**
 * @brief Check if a list is empty.
 * 
 * @param list the list
 * @return if the list is empty
 */
int			lst_is_empty(t_list *list);
/**
 * @brief Clear (see lst_clear) and free the list.
 * 
 * @param list the list
 */
void		lst_destroy(t_list *list);
/**
 * @brief Convert a list into a new array of elements and free the list.
 * 
 * @param list the list
 * @return the new array
 */
void		**as_arrayf(t_list *list);
/**
 * @brief Convert a list into a new array of elements.
 * 
 * @param list the list
 * @return the new array
 */
void		**as_array(t_list *list);
t_list		*lst_new(t_consumer del);
void		*lst_shift(t_list *list);
void		*lst_first(t_list *list);
/**
 * @brief Clear and free all elements of the list with the del function.
 * 
 * @param list the list
 */
void		lst_clear(t_list *list);
t_list		*lst_copy(t_list *list);
void		*lst_last(t_list *list);
int			lst_size(t_list *list);
void		lst_free(t_list *list);
void		*lst_pop(t_list *list);

void		*clst_find_first(t_clist *list, t_bipredicate comp, void *arg);
/**
 * @brief Append a custom entry at the end of the list
 * 
 * @param list the custom list
 * @param element the entry to add MUST START BY A `next` PROPERTY
 * @return the pushed element if success, NULL otherwise
 */
void		*clst_push(t_clist *list, void *entry);
t_centry	*clst_last_entry(t_clist *list);
int			clst_not_empty(t_clist *list);
int			clst_is_empty(t_clist *list);
void		clst_destroy(t_clist *list);
void		*clst_first(t_clist *list);
void		*clst_shift(t_clist *list);
void		clst_clear(t_clist *list);
t_clist		*clst_new(t_consumer del);

/*** Iterator implementation **************************************************/

struct s_iterator
{
	const t_list	*list;
	t_entry			*current;
};

struct s_citerator
{
	const t_clist	*list;
	t_centry		*current;
};

int			iterator_has_next(const t_iterator *iterator);
void		*iterator_next(t_iterator *iterator);
void		iterator_reset(t_iterator *iterator);
t_iterator	iterator_new(const t_list *list);

int			citerator_has_next(const t_citerator *iterator);
void		*citerator_next(t_citerator *iterator);
void		citerator_reset(t_citerator *iterator);
t_citerator	citerator_new(const t_clist *list);

/*** Colors implementation ****************************************************/

struct s_color
{
	float	r;
	float	g;
	float	b;
	float	a;
};

t_color		color_newa(t_uint8 r, t_uint8 g, t_uint8 b, t_uint8 a);
t_color		color_from_hsla(float h, float s, float l, float a);
/**
 * @brief Deserialize a color at format "r,g,b"
 * 
 * @param str the color at string format
 * @param color the container of the new color
 * @return the result of the operation : 1 if no error, 0 else
 */
int			color_deserialize(const char *str, t_color *color);
t_color		color_avg(const t_color v1, const t_color v2);
t_color		color_sub(const t_color v1, const t_color v2);
t_color		color_mul(const t_color v1, const t_color v2);
t_color		color_div(const t_color v1, const t_color v2);
t_color		color_add(const t_color v1, const t_color v2);
t_color		color_new(t_uint8 r, t_uint8 g, t_uint8 b);
t_color		color_from_hsl(float h, float s, float l);
t_color		color_mulf(const t_color v, float a);
t_color		color_divf(const t_color v, float a);
t_color		color_from_hexa(t_uint32 hex);
t_color		color_from_hex(t_uint32 hex);
t_uint32	color_to_hexa(const t_color c);
t_color		*color_clone(const t_color c);
t_uint32	color_to_hex(const t_color c);
t_color		color_copy(const t_color c);

/*** Print utils **************************************************************/

ssize_t		ft_puthex_fd(unsigned char c, int fd);
ssize_t		ft_putendl_fd(char *s, int fd);
ssize_t		ft_putchar_fd(char c, int fd);
ssize_t		ft_putstr_fd(char *s, int fd);
ssize_t		ft_putnbr_fd(long n, int fd);
ssize_t		ft_puthex(unsigned char c);
ssize_t		ft_putendl(char *s);
ssize_t		ft_putchar(char c);
ssize_t		ft_putstr(char *s);
ssize_t		ft_putnbr(long n);

/*** Math utils ***************************************************************/

int			ft_longlonglen_hex(unsigned long long n, int pre, int width);
int			ft_shortlen_hex(unsigned short n, int prefix, int width);
int			ft_longlen_hex(unsigned long n, int prefix, int width);
int			ft_charlen_hex(unsigned char n, int prefix, int width);
int			ft_intlen_hex(unsigned int n, int prefix, int width);
int			ft_longlonglen_octal(unsigned long long n);
int			ft_ulonglonglen(unsigned long long n);
int			ft_shortlen_octal(unsigned short n);
int			ft_longlen_octal(unsigned long n);
int			ft_charlen_octal(unsigned char n);
int			ft_intlen_octal(unsigned int n);
int			ft_ushortlen(unsigned short n);
int			ft_ulonglen(unsigned long n);
int			ft_ucharlen(unsigned char n);
int			ft_longlonglen(long long n);
int			ft_uintlen(unsigned int n);
double		ft_fabs(double number);
int			ft_shortlen(short n);
long		ft_abs(long number);
int			ft_longlen(long n);
int			ft_charlen(char n);
int			ft_intlen(int n);

int			fmaxi3(int x, int y, int z);
int			fmini3(int x, int y, int z);
int			fmaxi(int x, int y);
int			fmini(int x, int y);

/*** Converters implementation ************************************************/

/**
 * Write the unsigned int in the string dest in hexadecimal format.
 * 
 * @param n the int to convert
 * @param dest the buffer for the result
 * @return dest
 */
char		*ft_itohex_to(unsigned int n, char *dest, int prefix);
/**
 * Write the unsigned int in the string dest in octal format.
 * 
 * @param n the int to convert
 * @param dest the buffer for the result
 * @return dest
 */
char		*ft_itooctal_to(unsigned int n, char *dest);
/**
 * Write the int in the string dest in alphanumeric format.
 * 
 * @param n the int to convert
 * @param dest the buffer for the result
 * @return dest
 */
char		*ft_itoa_to(int n, char *dest);
/**
 * Write the unsigned int in the string dest in alphanumeric format.
 * 
 * @param n the int to convert
 * @param dest the buffer for the result
 * @return dest
 */
char		*ft_uitoa_to(unsigned int n, char *dest);
/**
 * @brief Same as ft_atoi, but set the written length in a variable
 * 
 * @param str the string to convert
 * @param len the written length
 * @return the final int
 */
int			ft_atoi_len(const char *str, int *len);
/**
 * Convert a number in hexadecimal format.
 * 
 * @param n the int to convert
 * @return a new string with the result
 */
char		*ft_itohex(unsigned int n, int prefix);
/**
 * Convert a number in octal format.
 * 
 * @param n the int to convert
 * @return a new string with the result
 */
char		*ft_itooctal(unsigned int n);
/**
 * Convert a number in alphanumeric format.
 * 
 * @param n the int to convert
 * @return a new string with the result
 */
char		*ft_uitoa(unsigned int n);
/**
 * @brief Convert a string to a float
 * 
 * @param str the string to convert
 * @param result the final float, same result as ft_atof
 * @return 1 if the result matches ('^-?[0-9]*(\.[0-9]+)?$'), 0 else
 */
int			ft_atof_full(char *str, float *result);
/**
 * @brief Convert a string to a float
 * 
 * Exemple
 * `ft_atof("42") == 42`
 * `ft_atof("") == 0`
 * `ft_atof("1234.5 1") == 1234.5`
 * `ft_atof(".21") == 0.21`
 * 
 * @param str the string to convert
 * @return the final float
 */
float		ft_atof(char *str);
/**
 * @brief Convert a string to a unsigned long
 * 
 * @param str the string to convert
 * @param result the final unsigned long, same result as ft_atof
 * @return 1 if the result matches ('^-?[0-9]+$'), 0 else
 */
int			ft_atoul_full(char *str, unsigned long *result);
/**
 * @brief Convert a string to a unsigned long
 * 
 * Exemple
 * `ft_atoul("42") == 42`
 * `ft_atoul("") == 0`
 * `ft_atoul("1234.5 1") == 1234.5`
 * `ft_atoul(".21") == 0.21`
 * 
 * @param str the string to convert
 * @return the final unsigned long
 */
t_ulong		ft_atoul(char *str);
/**
 * @brief Convert a string to a int
 * 
 * @param str the string to convert
 * @param result the final int, same result as ft_atof
 * @return 1 if the result matches ('^-?[0-9]+$'), 0 else
 */
int			ft_atoi_full(char *str, int *result);
/**
 * @brief Convert a string to a int
 * 
 * Exemple
 * `ft_atoi("42") == 42`
 * `ft_atoi("") == 0`
 * `ft_atoi("1234.5 1") == 1234.5`
 * `ft_atoi(".21") == 0.21`
 * 
 * @param str the string to convert
 * @return the final int
 */
int			ft_atoi(const char *str);
int			is_float(char *str);
char		*ft_itoa(int n);

/*** Miscellaneous ************************************************************/

int			ft_ternary(int condition, int expr1, int expr2);
t_bicon		null_biconsumer(void);
t_con		null_consumer(void);
t_fun		ft_identity(void);

#endif
