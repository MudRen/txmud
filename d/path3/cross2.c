// Room: /d/path3/cross2.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
����һƬ���֣���첽�������У���ϸ��Ѱ���Ųݵ���·��
�ۼ�����ΧһƬ�ž�������ͷ�����ӹ�һ˿������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"cross3",
  "northwest" : __DIR__"cross1",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
