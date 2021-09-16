// Room: /d/hangzhou/linpath5.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你正走在一条整齐的石子路上，路虽然不很宽，但清扫的很
是干净，这里向西就是林员外的卧房了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"linbedroom",
  "north" : __DIR__"linpath4",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
