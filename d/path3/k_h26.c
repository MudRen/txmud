// Room: /d/path3/k_h26.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
���ߵ����ֻ��·�����ߵ��������㷷�����������ּ���
����˷����������ߣ����ǳ����ɿ��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h27",
  "north" : __DIR__"k_h25",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
