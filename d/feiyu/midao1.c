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
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"neishi",
  "east" : __DIR__"midao2",
]));
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir =="east" && me->query("gender") == "男性" && me->query("class") != "rain") 
        {
                write (HIR"突然一阵乱剑向你射来！！！\n"NOR);
                write ("看来你根本没有办法过去。\n");
                return 0;
        }
return ::valid_leave(me, dir);
}
