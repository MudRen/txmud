// Room: chengxf5.c白虎堂

inherit ROOM;

void create()
{
        set("short", "白虎堂");
	set("long", @LONG
这里是长安丞相府的军议厅，一进门你首先可以看到上面一
块大匾，上书白虎堂四个大字，那字虬劲有力，入木三分，一看
就知，写这个字的人是武官出身，字里总能透出一种霸气，两边
站满跨刀的侍卫，杀气腾腾。从这里向东是直通前院的走廊。
LONG
	);

        set("exits", ([
  "east" : __DIR__"chengxf4",
]));
        set("item_desc", ([ /* sizeof() == 2 */
                "白虎堂": "白虎堂 三个大字，苍劲有力。\n",
]));

	set("objects",([
	__DIR__"npc/shiye" : 1,
]));

        setup();
	replace_program(ROOM);
}