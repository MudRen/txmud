// Room: /u/w/wangs/a/yu6.c

inherit __DIR__"patroling";

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一条小径上，两旁种满了松柏，四季常青，绿荫
满地，除了松涛声和鸟鸣声，听不到别的动静。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yu5",
  "east" : __DIR__"yu7",
]));
       set("outdoors","feiyu");

	setup();
}
