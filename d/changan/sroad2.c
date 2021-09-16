// Room: /d/changan/sroad2.c

inherit ROOM;

void create()
{
	set("short", "华瑞街");
	set("long", @LONG
这里长安城的南大街，而这一段正是江湖上艺人们打把式卖
艺的所在。你驻足于此，会看到三教九流的人物，在此卖弄他们
的看家本领。东面和西面仍在南大街上。南面是京城著名的四季
裁缝铺。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "changan");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"sroad3",
  "south" : __DIR__"caifeng",
  "west" : __DIR__"sroad1",
]));

	set("objects",([
	__DIR__"npc/yiren" : 1,
	__DIR__"npc/yi_girl" : 1,
]));

	setup();
	replace_program(ROOM);
}
