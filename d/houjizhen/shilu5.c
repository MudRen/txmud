// shilu5.c
// by dicky

inherit ROOM;

void create()
{
       set("short", "碎石路");
	set("long", @LONG
这是一段碎石路，路是用许多石块铺成的，铺的整整齐齐，
大路由东向西，一直通向侯集镇的尽头，北边是一济世堂，南边
是一家民居，西北方向有一条空荡荡的小巷。
LONG
	);

        set("outdoors", "houjizhen");

	set("exits", ([ 
	    "west" : __DIR__"shilu6",
	    "north" : __DIR__"yaopu",
	    "south" : __DIR__"minju1",
	    "northwest" : __DIR__"xiaoxiang",
	    "east" : __DIR__"shilu4",
	]));

	set("objects", ([
		__DIR__"npc/seller" : 1,
	]));

	setup();
	replace_program(ROOM);
}
