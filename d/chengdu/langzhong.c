// Room: /wiz/louth/c/langzhong.c

inherit ROOM;

void create()
{
	set("short", "朗中家");
	set("long", @LONG
这是成都著名的朗中苏理明开设的药房，许多人都到这里来
看病。每天这里都会络绎不绝的有病人看病，抓药。因为郎中的
医术出众，被人誉为“在世华佗”。从这里往南就是锦官路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jguanlu2",
]));

	set("objects",([
	__DIR__"npc/doctor" : 1,
]));

	setup();
	replace_program(ROOM);
}
