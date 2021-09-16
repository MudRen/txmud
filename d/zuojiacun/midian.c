// Room: /d/zuojiacun/midian.c

inherit ROOM;

void create()
{
	set("short", "Ã××¯");
	set("long", @LONG
ÔÝÎ´Éè¼Æ
LONG
	);
	set("no_clean_up", 0);
//	set("exits", ([ /* sizeof() == 1 */
//  "east" : __DIR__"lu14",
// ])); 

	setup();
	replace_program(ROOM);
}
