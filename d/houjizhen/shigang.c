//shigang.c
//by dicky

inherit ROOM;

void create()
{
set("short", "乱石岗");
	set("long", @LONG
你正在一条崎岖不平的乱石岗上，偶尔听到一阵阵的野兽嚎叫声，头顶
有一些不知名的小鸟在跳来跳去，四周丛林密布，野花绿草若隐若现，阵阵
凉风吹来，你忽然有一种毛骨耸然的感觉,不由的加快了脚步。
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([ /* sizeof() == 1 */
	    "southeast" : __DIR__"tomb",
	    "northup" : __DIR__"shanpo",
	    "west" : __DIR__"lzxiaolu",
]));

//	set("objects", ([
//		__DIR__"npc/tufei" : 3,
//		]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

#include "heiyijob.h";