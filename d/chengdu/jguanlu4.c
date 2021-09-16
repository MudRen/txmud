// Room: /wiz/louth/c/jguanlu4.c

inherit ROOM;

void create()
{
	set("short", "锦官路");
	set("long", @LONG
这里是成都的锦官路。北边是武王道，一直可以走到万明路。
向南就是成都的伐木场。向西是成都的王建墓。向东可以穿过成
都北部的十字路口和锦官路。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wjmu",
  "east" : __DIR__"jguanlu3",
  "north" : __DIR__"wwdao5",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
