// Room: /d/changan/sroad9.c

inherit ROOM;

void create()
{
	set("short", "南安大道");
	set("long", @LONG
这是就是南北直通皇宫的南安大道，也是长安人通常所说的
四条官道之一，不时的有朝廷中的快马打此经过，要不就是出入
长安城的官员，到处都得回避。百姓们每次走到这条路上，都不
由的战战兢兢。从这里向南是华瑞街，往北直通皇宫的南门，西
面是一家客栈，东面不远就是小镜湖了。
LONG
	);

	set("outdoors", "changan");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"hu_bank",
  "south" : __DIR__"sroad4",
  "west" : __DIR__"kezhan",
  "north" : __DIR__"shroad2",
]));

	set("objects",([
	__DIR__"npc/beggar" : 1,
	NPC_DIR"xunpu" : 2,
]));

	setup();
	replace_program(ROOM);
}
