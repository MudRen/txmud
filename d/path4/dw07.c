// Room: /d/path4/dw07.c

inherit ROOM;

void create()
{
	set("short", "ԭʼɭ�ֱ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"dw06",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
