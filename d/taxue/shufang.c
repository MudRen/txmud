// shufang.c
// by dicky

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "书房");
        set("long", @LONG
这里是老庄主的书房，但庄主已经很久没来这里了。到是踏雪靖远的四弟子踏
雪莫匆经常来这里，顺便指导一些喜欢读书的弟子们。书房周围的书架上整整齐齐
地堆放着很多书籍。正对大门的那边墙上写了几个醒目的大字（dazi）。
LONG
        );
        set("item_desc", ([
		"dazi" : HIY"
    ※※※※※※※※※※※※※※※※※※※
    ※※※※　　　　　　　　　　　※※※※
    ※※※※　                    ※※※※
    ※※※※ 　 　少壮不努力，　　※※※※
    ※※※※　                    ※※※※
    ※※※※　　　　　　　　　　  ※※※※
    ※※※※　                    ※※※※
    ※※※※ 　 　老大徒悲伤。  　※※※※
    ※※※※　                    ※※※※
    ※※※※　　　　　　　　　　　※※※※
    ※※※※※※※※※※※※※※※※※※※\n"NOR ,
 
	]));

        set("exits", ([
                "northeast" : __DIR__"xiting",
        ]));


        set("objects", ([
		__DIR__"npc/dizi3":1,
        ]));

        setup();
	replace_program(ROOM);
}
