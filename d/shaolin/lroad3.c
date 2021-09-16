// Room: /d/shaolin/lroad3.c

inherit ROOM;

void create()
{
	set("short", "过道");
	set("long", @LONG
这里是少林寺的过道，因为这里地近斋堂，所以一到斋饭时
间，人来人往的好不热闹。少林寺的僧人不比别的寺，各安所命，
所以，一般也见不到什么人乱逛。从这里向西是西跨院，向南是
西广场，往东北方便是青石甬道了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"yongdao1",
  "south" : __DIR__"w_square",
  "west" : __DIR__"w_court",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
}

int valid_leave(object ob,string dir)
{
	if(!ob || !stringp(dir))
		return 1;

	if( (dir == "west" || dir == "w")
	&& ob->query("class") != "shaolin"
	&& !wizardp(ob) )
		return notify_fail("非少林寺弟子不得入内！！\n");

	else
		return ::valid_leave(ob,dir);
}