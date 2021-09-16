// milin2.c
// by dicky 2002-12-9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山中密林");
	set("long", @LONG
这里是山中密林，几十丈高的大松树簇在一块，密实的枝叶象一蓬蓬巨伞
般伸向天空，把阳光遮得丝毫也无。仰望北面高崖，白雾封谷，林中静悄悄的
，别说人迹，就连兽踪也无半点，唯闻鸟语相间，遥相和呼。
LONG);

        set("outdoors", "taxue");

        set("exits", ([
	    "west" : __DIR__"milin1",
	    "north" : __DIR__"shanya-s",
	]));

	setup();
	replace_program(ROOM);
}
