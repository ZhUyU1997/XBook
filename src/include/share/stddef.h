/*
 * file:		include/share/stdarg.h
 * auther:		Jason Hu
 * time:		2019/6/2
 * copyright:	(C) 2018-2019 by Book OS developers. All rights reserved.
 */

#ifndef _SHARE_STDDEF_H
#define _SHARE_STDDEF_H


/*
 *这里是typedef类型的
 */

/* 32位操作系统 */
typedef unsigned int flags_t;
typedef unsigned int size_t;
typedef unsigned int register_t;    //寄存器
typedef unsigned int address_t;    //地址类型的变量

/* 64位操作系统 */
/*
typedef unsigned long flags_t;
typedef unsigned long size_t;
typedef unsigned long register_t;
typedef unsigned long address_t;
 */


/*
 *这里是define类型的
 */
#define WRITE_ONCE(var, val) \
        (*((volatile typeof(val) *)(&(var))) = (val))

/*
 * 我只能把大名鼎鼎的container_of宏直接学习过来了。 (*^.^*)
 */

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({ \
    const typeof( ((type *)0)->member ) *__mptr = (ptr); \
    (type *)( (char *)__mptr - offsetof(type,member) ); \
})


#endif  /*_SHARE_STDDEF_H*/
