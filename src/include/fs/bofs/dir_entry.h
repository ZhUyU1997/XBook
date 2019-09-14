/*
 * file:		include/fs/bofs/dir_entry.h
 * auther:		Jason Hu
 * time:		2019/9/5
 * copyright:	(C) 2018-2019 by Book OS developers. All rights reserved.
 */

#ifndef _BOFS_DIR_ENTRY_H
#define _BOFS_DIR_ENTRY_H

#include <share/stdint.h>
#include <share/types.h>

/*book os file system dir entry*/

#define BOFS_NAME_LEN (256-10)

#define BOFS_FILE_TYPE_UNKNOWN 		0X00
#define BOFS_FILE_TYPE_NORMAL 		0X01
#define BOFS_FILE_TYPE_DIRECTORY 	0X02
#define BOFS_FILE_TYPE_MOUNT 	    0X04
#define BOFS_FILE_TYPE_INVALID 		0X80

#define BOFS_PATH_LEN 	256

struct BOFS_DirEntry
{
	unsigned int inode;			/*inode number*/
	unsigned short type;	/*file type*/
    unsigned int mount;	    /* 挂载关联（超级块地址） */
    
	char name[BOFS_NAME_LEN];	/*name length(0~255)*/
}__attribute__ ((packed));;

#define BOFS_SIZEOF_DIR_ENTRY 	(sizeof(struct BOFS_DirEntry))

#define BOFS_DIR_NR_IN_SECTOR 	(SECTOR_SIZE/BOFS_SIZEOF_DIR_ENTRY)

PUBLIC void BOFS_CreateDirEntry(struct BOFS_DirEntry *dirEntry,
    unsigned int inode,
    unsigned short type,
	unsigned int mount,
    char *name);

void BOFS_DumpDirEntry(struct BOFS_DirEntry *dirEntry);

void BOFS_CloseDirEntry(struct BOFS_DirEntry *dirEntry);

#endif	/* _BOFS_DIR_ENTRY_H */
