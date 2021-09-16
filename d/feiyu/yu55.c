// Room: /u/w/wangs/a/yu55.c

inherit ROOM;

void create()
{
	set("short", "梅林阁");
	set("long", @LONG
阁内的桌凳、花窗、地坪、书画皆取材于梅花，并悬匾
额“绮窗春讯”。阁前种植了许多枝梅，以符阁名。为著书、
绘画之处。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"yu54",
  "up" : __DIR__"yu56",
]));

	set("outdoors","feiyu");

	setup();
}
/*
int valid_leave(object me, string dir)
{
	if( dir =="up"
	&& !wizardp(me)
	&& ((me->query("combat_exp") < 1500000)
	|| (me->query("class") != "rain")) )
	{
		if(objectp(present("zhang suifeng", environment(me))))
			return notify_fail("张绋冰道：你不能进入梅林阁！\n");
	}
	return ::valid_leave(me, dir);
}
*/
