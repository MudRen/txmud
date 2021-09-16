// Room: /d/changan/sroad7.c

inherit ROOM;

void create()
{
	set("short", "华瑞街");
	set("long", @LONG
这里长安城的南大街的东边地带，来来往往的人不少，但都
是行色匆匆。南面是京城最大的骡马市，也是内地骡马的集散地，
各地的马贩子都汇集这里进行交易。各地的马贩子，争厢介绍着
自己的马匹，不时传来一声声马的嘶叫。
LONG
	);

	set("outdoors", "changan");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/cleaner" : 1,
]));

	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"sroad6",
  "south" : __DIR__"mashi",
  "east" : __DIR__"sroad8",
]));

	set("objects",([
	NPC_DIR"xunpu" : 2,
	NPC_DIR"stdnpc/stdnpc_3" : 2,
]));
	setup();
	replace_program(ROOM);
}
