// Room: /wiz/louth/a/zting.c

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"xlu2",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
