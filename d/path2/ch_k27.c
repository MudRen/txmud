// Room: /d/path2/ch_k27.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ����������������ĳ�������������������˲���
�ϵĺ��飬̧ͷ���˿����׵����գ����в����������䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"ch_k28",
  "northwest" : __DIR__"ch_k26",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
