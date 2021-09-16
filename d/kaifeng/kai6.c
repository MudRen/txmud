// Room: /wiz/louth/k/kai6.c

inherit ROOM;

void create()
{
	set("short", "武场内院");
	set("long", @LONG
这里是天虹武场的内院，天虹武场的弟子们一般是不让到这
里的，只有功夫和人品特别好的弟子，柳师父才让他到这里传他
一些高深的武功。这里打扫得非常干净，院落拐角种着一颗粗大
的槐树。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai5",
]));
        set("objects",([
        __DIR__"npc/jiaotou" : 1,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
