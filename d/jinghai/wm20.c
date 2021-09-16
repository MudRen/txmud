// Room: /d/jinghai/wm20.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
空阔的场地上铺满了细细的黄土，正好适合练武。场子的周
围摆满了一排一排的兵器架，上面尽是各式各类的奇门兵器。海
靖派的门人弟子们经常在这里切磋武艺，交流心得。南边有一条
小路延至远方，不知通向何处。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wm8",
]));
        set("objects",([
        __DIR__"npc/yong7" : 3,
]));


        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
