// Room: /u/w/wangs/a/yu10.c

inherit __DIR__"patroling";

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一条小径上，两旁种满了松柏，四季常青，绿荫
满地，除了松涛声和鸟鸣声，听不到别的动静。南面似乎有
一座简陋的小院。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"yu13",
  "northwest" : __DIR__"yu9",
  "east" : __DIR__"yu11",
]));
       set("outdoors","feiyu");

	setup();
}
