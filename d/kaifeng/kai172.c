// Room: /u/w/wangs/b/kai172.c

inherit ROOM;

void create()
{
	set("short", "包子铺");
	set("long", @LONG
铺子里的摆设并不是很讲究，横竖摆了几排圆木方桌，桌子
四周零乱的放了几把长条椅子。一个小伙计没精打采的靠在柜台
边，看见你进来，只是懒洋洋的向你打了个招呼。看起来这里的
生意并不怎么好。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai171",
]));
        set("objects",([
        __DIR__"npc/bboss": 1,
]));

	setup();
	replace_program(ROOM);
}
