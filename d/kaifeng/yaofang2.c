// Room: /d/kaifeng/yaofang2.c

inherit ROOM;

void create()
{
	set("short", "ҩ���˷�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai111",
]));

	set("objects",([
	__DIR__"npc/doctor_hu" : 1,
]));

	setup();
	replace_program(ROOM);
}
