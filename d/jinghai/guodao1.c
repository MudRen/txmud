// Room: /d/jinghai/guodao1.c

inherit ROOM;

void create()
{
	set("short", "��Ժ����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"wofang",
  "northeast" : __DIR__"dating",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
