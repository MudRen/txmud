// Room: /u/w/wangs/a/yu11.c

inherit ROOM;

void create()
{
	set("short", "小木门");
	set("long", @LONG
你来到一个小木门前。看上去虽不是很豪华，但显得挺
别致。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"yu12",
  "west" : __DIR__"yu10",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
