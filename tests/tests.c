/*
** EPITECH PROJECT, 2024
** asmminilibc
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t (*my_strlen)(const char *);
static char *(*my_strchr)(const char *, int);
static char *(*my_index)(const char *, int);
static char *(*my_rindex)(const char *, int);
static char *(*my_strrchr)(const char *, int);
static void *(*my_memset)(void *, int, size_t);
static void *(*my_memcpy)(void *, void *, size_t);
static void *(*my_memmove)(void *, void *, size_t);
static void *(*my_memfrob)(void *, size_t);
static int (*my_strcmp)(const char *, const char *);
static char *(*my_strstr)(const char *, const char *);
static char *(*my_strpbrk)(const char *, const char *);
static int (*my_strcasecmp)(const char *, const char *);
static size_t (*my_strcspn)(const char *, const char *);
static int (*my_strncmp)(const char *, const char *, size_t);

void init_all()
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    my_strlen = dlsym(handle, "strlen");
    my_strchr = dlsym(handle, "strchr");
    my_strrchr = dlsym(handle, "strrchr");
    my_memset = dlsym(handle, "memset");
    my_memcpy = dlsym(handle, "memcpy");
    my_memmove = dlsym(handle, "memmove");
    my_strcmp = dlsym(handle, "strcmp");
    my_strpbrk = dlsym(handle, "strpbrk");
    my_strstr = dlsym(handle, "strstr");
    my_strncmp = dlsym(handle, "strncmp");
    my_strcasecmp = dlsym(handle, "strcasecmp");
    my_strcspn = dlsym(handle, "strcspn");
    my_index = dlsym(handle, "index");
    my_rindex = dlsym(handle, "rindex");
    my_memfrob = dlsym(handle, "memfrob");
    // dlclose(handle);
}

Test(test_bas, basic, .init = init_all)
{
size_t lenght = my_strlen("hello");
cr_assert_eq(strlen("hello"), lenght);
}

Test(test_bas_chr, basic, .init = init_all)
{
char *test = my_strchr("hello", 'e');
cr_assert_eq(strchr("hello", 'e'), test);
}

Test(test_bas_chr_fail, basic, .init = init_all)
{
char *test = my_strchr("hello", 2);
cr_assert_eq(strchr("hello", 2), test);
}

Test(test_bas_chrr, basic, .init = init_all)
{
char *test = my_strrchr("hello", 'l');
cr_assert_eq(strrchr("hello", 'l'), test);
}

Test(test_empty_string, empty, .init = init_all)
{
char *test = my_strrchr("", 'a');
cr_assert_eq(strrchr("", 'a'), test);
}

Test(test_char_not_found, not_found, .init = init_all)
{
char *test = my_strrchr("hello", 'z');
cr_assert_eq(strrchr("hello", 'z'), test);
}

Test(test_single_char_string, single_char, .init = init_all)
{
char *test = my_strrchr("a", 'a');
cr_assert_eq(strrchr("a", 'a'), test);
}

Test(test_multiple_chars, multiple_chars, .init = init_all)
{
char *test = my_strrchr("hello world", 'o');
cr_assert_eq(strrchr("hello world", 'o'), test);
}

Test(test_multiple_chars_last, multiple_chars_last, .init = init_all)
{
char *test = my_strrchr("hello world", 'd');
cr_assert_eq(strrchr("hello world", 'd'), test);
}

Test(test_bas_chrr_fail, basic, .init = init_all)
{
char *test = my_strrchr("hello", 2);
cr_assert_eq(strrchr("hello", 2), test);
}

Test(test_bas_memset, basic, .init = init_all)
{
int array[] = {54, 85, 20, 63, 21};
size_t size = sizeof(int) * 5;
cr_assert_eq(memset(array, 0, size), my_memset(array, 0, size));
}

Test(test_bas_memcpy, basic, .init = init_all)
{
int array[] = {54, 85, 20, 63, 21};
int array_src[] = {10, 11, 12, 13, 14};
size_t size = sizeof(int) * 5;
cr_assert_eq(memcpy(array, array_src, size),
        my_memcpy(array, array_src, size));
}

Test(test_strcmp, basic, .init = init_all)
{
cr_assert_eq(strcmp("hello", "hello"), my_strcmp("hello", "hello"));
}

Test(test_strcmp_2, basic, .init = init_all)
{
cr_assert_eq('o', my_strcmp("hello", "hell"));
}

Test(test_strcmp_3, basic, .init = init_all)
{
cr_assert_eq(-'o', my_strcmp("hell", "hello"));
}

Test(test_strcmp_4, basic, .init = init_all)
{
cr_assert_eq('l' - 'o', my_strcmp("hello", "helo"));
}

Test(test_strcmp_5, basic, .init = init_all)
{
cr_assert_eq('o' - 'l', my_strcmp("helo", "hello"));
}

Test(test_strncmp, basic, .init = init_all)
{
cr_assert_eq(strncmp("hello", "hello", 3), my_strncmp("hello", "hello", 3));
}

Test(test_strncmp_2, basic, .init = init_all)
{
cr_assert_eq(strncmp("hello", "hell", 4), my_strncmp("hello", "hell", 4));
}

Test(test_strncmp_3, basic, .init = init_all)
{
cr_assert_eq(strncmp("hell", "hello", 3), my_strncmp("hell", "hello", 3));
}

Test(test_strncmp_4, basic, .init = init_all)
{
cr_assert_eq('l' - 'o', my_strncmp("hello", "helo", 5));
}

Test(test_strncmp_5, basic, .init = init_all)
{
cr_assert_eq('o' - 'l', my_strncmp("helo", "hello", 5));
}

Test(test_memmove_1, basic, .init = init_all)
{
char *s = strdup("Hello World");
char *s2 = strdup("");
cr_assert_eq(my_memmove(s, s2, 1), memmove(s, s2, 1));
}

Test(test_memmove2, basic, .init = init_all)
{
char *s = strdup("");
char *s2 = strdup("Hello World");
cr_assert_eq(my_memmove(s, s2, 1), memmove(s, s2, 1));
}

Test(test_memmove3, basic, .init = init_all)
{
char *s = strdup("");
char *s2 = strdup("");
cr_assert_eq(my_memmove(s, s2, 1), memmove(s, s2, 1));
}

Test(test_memmove4, basic, .init = init_all)
{
char *s = strdup("test with something and random value");
cr_assert_eq(memmove(s + 4, s + 17, 11), my_memmove(s + 4, s + 17, 11));
}

Test(test_memmove5, basic, .init = init_all)
{
char *s = strdup("test with something and random value");
cr_assert_eq(memmove(s + 10, s + 5, 17), my_memmove(s + 10, s + 5, 17));
}

Test(test_strcasecmp_1, basic, .init = init_all)
{
cr_assert_eq(my_strcasecmp("HellO", "WoRlD"), strcasecmp("HellO", "WoRlD"));
cr_assert_eq(my_strcasecmp("WoRlD", "HellO"), strcasecmp("WoRlD", "HellO"));
cr_assert_eq(my_strcasecmp("hello", "HellO"), strcasecmp("hello", "HellO"));
cr_assert_eq(my_strcasecmp("zello", "ZellO"), strcasecmp("zello", "ZellO"));
cr_assert_eq(my_strcasecmp("Zello", "zellO"), strcasecmp("Zello", "zellO"));
cr_assert_eq(my_strcasecmp("aello", "AellO"), strcasecmp("aello", "AellO"));
cr_assert_eq(my_strcasecmp("Aello", "AellO"), strcasecmp("Aello", "aellO"));
}

Test(test_strcasecmp_2, basic, .init = init_all)
{
cr_assert_eq(my_strcasecmp("HEllO WorlD", ""),
strcasecmp("HEllO WorlD", ""));
cr_assert_eq(my_strcasecmp("HEllO WorlD", "HEllO WorlD"),
strcasecmp("HEllO WorlD", "HEllO WorlD"));
cr_assert_eq(my_strcasecmp("HEllO WorlD", ""),
strcasecmp("HEllO WorlD", ""));
cr_assert_eq(my_strcasecmp("", ""), strcasecmp("", ""));
cr_assert_eq(my_strcasecmp("", ""), strcasecmp("", ""));
cr_assert_eq(my_strcasecmp("", ""), strcasecmp("", ""));
}

Test(test_strcasecmp_3, basic, .init = init_all)
{
cr_assert_eq(my_strcasecmp("HellO", "HellO"), strcasecmp("HellO", "HellO"));
}

Test(test_strstr, basic, .init = init_all)
{
char *s1 = strdup("hello");
char *s2 = strdup("world");
cr_assert_eq(my_strstr(s1, s2), strstr(s1, s2));
cr_assert_eq(my_strstr(s2, s1), strstr(s2, s1));
cr_assert_eq(my_strstr(s2, s2), strstr(s2, s2));
}

Test(test_strstr_2, basic, .init = init_all)
{
char *s1 = strdup("");
char *s2 = strdup("hello");
cr_assert_eq(my_strstr(s1, s2), strstr(s1, s2));
cr_assert_eq(my_strstr(s2, s1), strstr(s2, s1));
cr_assert_eq(my_strstr(s1, s1), strstr(s1, s1));
}

Test(test_strstr_3, basic, .init = init_all)
{
char *s1 = strdup("");
char *s2 = strdup("");
cr_assert_eq(my_strstr(s1, s2), strstr(s1, s2));
}

Test(test_strstr_4, basic, .init = init_all)
{
char *s1 = strdup("hello");
char *s2 = strdup("hello");
cr_assert_eq(my_strstr(s1, s2), strstr(s1, s2));
cr_assert_eq(my_strstr(s2, s2), strstr(s2, s2));
}

Test(test_strpbrk, basic, .init = init_all)
{
char *s1 = strdup("hello");
cr_assert_eq(my_strpbrk(s1, "el"), strpbrk(s1, "el"));
cr_assert_eq(my_strpbrk(s1, "h"), strpbrk(s1, "h"));
}

Test(test_strpbrk_2, basic, .init = init_all)
{
char *s1 = strdup("hello");
cr_assert_eq(my_strpbrk(s1, ""), strpbrk(s1, ""));
cr_assert_eq(my_strpbrk("", "hello"), strpbrk("", "hello"));
cr_assert_eq(my_strpbrk("", ""), strpbrk("", ""));
}

Test(test_strpbrk_3, basic, .init = init_all)
{
cr_assert_eq(my_strpbrk("", ""), strpbrk("", ""));
}

Test(test_strpbrk_4, basic, .init = init_all)
{
char *s1 = strdup("hello");
cr_assert_eq(my_strpbrk(s1, s1), strpbrk(s1, s1));
}

Test(test_strcspn, basic, .init = init_all)
{
cr_assert_eq(my_strcspn("test", "es"), strcspn("test", "es"));
cr_assert_eq(my_strcspn("test", "t"), strcspn("test", "t"));
cr_assert_eq(my_strcspn("test", ""), strcspn("test", ""));
cr_assert_eq(my_strcspn("", "test"), strcspn("", "test"));
cr_assert_eq(my_strcspn("", ""), strcspn("", ""));
cr_assert_eq(my_strcspn("test", "test"), strcspn("test", "test"));
}

Test(test_index_1, basic, .init = init_all)
{
cr_assert_eq(my_index("test", 't'), index("test", 't'));
cr_assert_eq(my_index("test", 'w'), index("test", 'w'));
cr_assert_eq(my_index("test", '\0'), index("test", '\0'));
cr_assert_eq(my_index("", 'p'), index("", 'p'));
cr_assert_eq(my_index("", '\0'), index("", '\0'));
}

Test(test_strncmp_end, basic, .init = init_all)
{
cr_assert_eq(my_strncmp("Hello", "Hello world", 5),
strncmp("Hello", "Hello world", 5));
}