// Room: /u/w/wangs/b/kai55.c

inherit ROOM;

void create()
{
	set("short", "立山街");
	set("long", @LONG
这是一穿行在民居的墙壁与城墙之间的小街道，与其说它是
街还不如说是一条小巷，这窄窄的巷子里自然也没有什么摊贩，
至于为什么被叫做立山街已经无从考证了，不过这里人来人往，
倒也十分热闹。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"kai54",
  "east" : __DIR__"kai58",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
