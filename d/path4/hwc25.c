// Room: /d/path4/hwc25.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hwc26",
  "northeast" : __DIR__"hwc24",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
