// Room: /d/shaolin/rroad3.c

inherit ROOM;

void create()
{
	set("short", "过道");
	set("long", @LONG
这里是少林寺的过道，这里是去休息室的必经之地，所以每
到晚课结束后，三三两两的僧人从这里走过。从这里向东是东跨
院，向南是东广场，西北方则通往青石甬道。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"yongdao1",
  "south" : __DIR__"e_square",
  "east" : __DIR__"e_court",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
}

int valid_leave(object ob,string dir)
{
	if(!ob || !stringp(dir))
		return 1;

	if( (dir == "east" || dir == "e")
	&& ob->query("class") != "shaolin"
	&& !wizardp(ob) )
		return notify_fail("非少林寺弟子不得入内！！\n");

	else
		return ::valid_leave(ob,dir);
}