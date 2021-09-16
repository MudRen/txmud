// Room: /d/changan/jinghu.c

inherit ROOM;

void create()
{
	set("short", "小镜湖");
	set("long", @LONG
这里是京城里闻名的小镜湖，湖水清澈见底，在喧闹的大都
市里一方自然的净土，湖边栽满了柳树，每逢夏天绿树成荫，不
知吸引了多少文人骚客来这里泛舟湖上吟诗做赋。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"sroad5",
  "north" : __DIR__"hu_bank",
]));

	set("objects",([
	__DIR__"npc/juzi" : 1,
]));

	set("outdoors","changan");
	setup();
	replace_program(ROOM);
}
