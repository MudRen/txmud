// Room: /wiz/louth/a/caodi2.c

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是一片青青的草地，稀疏的长着几棵小树，偶尔传来几声
小鸟的鸣叫，使人感受到一种静谧的气氛。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"taoyuan10",
  "north" : __DIR__"caodi3",
]));
        set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
