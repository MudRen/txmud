// Room: /d/changan/wroad5.c

inherit ROOM;

void create()
{
    set("short", "小房间");
	set("long", @LONG
一个空房间而已。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
]));

	set("objects",([
     "/open/taxue/boy.c":1,
    "/open/taxue/boss.c":1,
]));

	setup();
	replace_program(ROOM);
}
