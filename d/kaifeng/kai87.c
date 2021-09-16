// Room: /u/w/wangs/b/kai87.c

inherit ROOM;

void create()
{
	set("short", "驿站");
	set("long", @LONG
这里是开封府官家的驿站，由于开封商业发达，而官家的驿
站传送文书、信件之类的东西非常的迅速、安全，所以现在很多
商人也通过这里把一些重要的文书送到外地，当然，官府是要收
钱的。这里不停的有信使到来或出发，一派繁忙的景象。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai86",
]));

	setup();
	replace_program(ROOM);
}
