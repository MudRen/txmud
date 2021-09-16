// Room: /d/shaolin/bingqiku.c

inherit ROOM;

void create()
{
	set("short", "兵器库");
	set("long", @LONG
这里是少林寺的兵器库，出家人已慈悲为怀，一些兵器都是
封在库里的。少林的僧兵大都用棍，偶有人使用禅杖或是锡杖，
而兵器库里的兵器却是很多，戒刀、宝剑一应俱全。只要在遇到
外敌来侵时，才可以使用这里的兵器。从这里向南是东跨院。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"e_court",
]));

	set("objects", ([
	WEAPON_DIR"stick" : 2,
	__DIR__"npc/obj/jiedao" : 2,
	WEAPON_DIR"sword" : 1,
]));

	setup();
	replace_program(ROOM);
}
