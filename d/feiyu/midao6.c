#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "秘道");
	set("long", @LONG
这是一条狭小漆黑的密道，周围清冷的石壁上挂着水珠，上
面有几个小黑洞。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"midao2",
  "east" : __DIR__"midao7",
  "south" : __DIR__"midao5",
  "north" : __DIR__"midao3",
]));
	setup();
}

int valid_leave(object me,string dir)
{
        me->receive_damage("kee",10);
        me->receive_damage("gin",10);
        me->receive_damage("sen",10);
        message_vision(HIR"四周忽然向你射来无数短箭，$N顿时身中数箭！\n"NOR,me);
return 1;
}
