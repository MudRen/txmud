// songshulin.c
// by dicky 2002-12-9

inherit ROOM;

void create()
{
	set("short", "山中密林");
	set("long", @LONG
你眼前骤然一黑，朦胧中，只见左右前后，到处都是铺天盖地的松树林
。几十丈高的大松树簇在一块，密实的枝叶象一蓬蓬巨伞般伸向天空，把阳
光遮得丝毫也无。尺把厚的松针积在地上，一脚踩下去，半天拔不出来。
LONG);


	set("outdoors", "taxue");

	set("exits", ([
		"east" : __DIR__"milin2",
		"south" : __DIR__"undertree",
	]));

	setup();
	replace_program(ROOM);
}



