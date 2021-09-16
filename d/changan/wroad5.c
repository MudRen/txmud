// Room: /d/changan/wroad5.c

inherit ROOM;

void create()
{
	set("short", "永泰路");
	set("long", @LONG
这里是长安城的西大街，路两边有一些生意人，在做着生意。
一些衙门也坐落在这条街上，经常有一些鸣锣开道的官轿从这里
经过。街上捕快来来往往。永泰路由这里向南北延伸。路西是一
家水果铺。
LONG
	);
	set("outdoors", "changan");

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"wroad6",
  "west" : __DIR__"fruitroom",
  "north" : __DIR__"wroad4",
]));

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 3,
]));

	setup();
	replace_program(ROOM);
}
