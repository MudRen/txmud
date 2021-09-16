// Room: /d/path1/ft_s5.c

inherit ROOM;

void create()
{
	set("short", "赵公口");
	set("long", @LONG
这里就是赵公口。再向东去有一条大道通向奉天城，向西则
是一条崎岖山路，南面通往柏云坡。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"zjz1",
  "west" : __DIR__"ft_s4",
  "east" : __DIR__"ft_s6",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
