// Room: /d/shaolin/shanquan.c

inherit ROOM;

void create()
{
	set("short", "山泉");
	set("long", @LONG
你正站在一个精巧的小瀑布前面，清澈的山泉从山崖上一泻
而下，在你脚下形成一条涓涓的小溪静静地向山下流淌。据说少
林寺的和尚每天都来这里打水(dashui)。
LONG
	);

	set("outdoors", "shaolin");

	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"shandao5",
]));

	setup();
}

void init()
{
	add_action("do_dashui","dashui");
}

int do_dashui()
{
	object ob;

	ob = present("shui tong",this_player());
	if(!ob)
		return 0;

	message_vision("$N拎起水桶在山泉里打了一桶泉水。\n",this_player());
	ob->delete("no_water");
	return 1;
}