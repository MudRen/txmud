// Room: /d/changan/mashi.c

inherit ROOM;

void create()
{
	set("short", "骡马市");
	set("long", @LONG
这里是长安城的骡马市，迎面是一排马厩，不时传来骡马的
鸣叫声。买马的人流来往不断。由于京城多达官贵人，所以骡马
的价格也很高，外地的马贩子也经常贩马来给这里的骡马市。一
个马贩子正坐在这里，不时的和来买马的人讨价还价。
LONG
	);


	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"sroad7",
]));
	set("no_clean_up", 0);
	set("objects",([
	__DIR__"npc/ma-fanzi" : 1,
]));
	set("outdoors","changan");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
