// caidi.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","菜地");
        set("long", @LONG
这里是一座极大的菜园，种满了油菜，萝卜，茄子，丝瓜之类。周围的篱
笆都破了，看来要整修了。由于长期得不到良好的照顾，菜地里杂草丛生，种
的菜都长势不好，蔫蔫的，地都荒了。
LONG
        );

        set("outdoors", "taxue");
        
        set("exits", ([
		"south" : __DIR__"houyuan",
		"north" : __DIR__"shilu4",
        ]) );

        setup();
        replace_program(ROOM);
}

