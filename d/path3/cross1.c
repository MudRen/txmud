// Room: /d/path3/cross1.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
����һƬ���֣����������פ����ˡ����������У���ϡ��
�Է��ֲݵ���·�ĺۼ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"cross2",
  "northwest" : __DIR__"k_s4",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
