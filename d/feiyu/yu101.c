// yu101.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "后花园");
	set("long", @LONG
这里是绯雨阁里的小花园，种植着一些叫不出名字来的
花木。这个花园虽然不大，但整理的井井有条，看的出主人
下了一番功夫。东面有一个小院。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"yu100",
  "east" : __DIR__"yu102",
]));
	set("outdoors","feiyu");

	setup();
}

int valid_leave(object me, string dir)
{
	if( (dir =="east") && !wizardp(me) && (me->query("class") != "rain") )
		return notify_fail(HIM"一股阴柔之力挡住了你。。。\n\n"NOR);
	return ::valid_leave(me, dir);
}
