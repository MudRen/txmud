// Room: /wiz/louth/c/shizi.c

inherit ROOM;

void create()
{
	set("short", "十字路口");
	set("long", @LONG
这里是成都南部的十字路口。在这里向北走是宝光寺。向南
不远是成都城的南城门。东西方向可以通过整个锦官路。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"jguanlu1",
  "south" : __DIR__"sdoor",
  "east" : __DIR__"jguanlu5",
  "north" : __DIR__"guangbaosi",
]));
        set("objects",([
        __DIR__"npc/luren" : 1,
	NPC_DIR"xunpu" : 2,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
