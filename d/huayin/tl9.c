// Room: /d/huayin/tl9.c

inherit ROOM;

void create()
{
	set("short", "��ɽ·");
	set("long", @LONG
����һ����ʯ���̾͵���խ����ɽС·��ʯ�׺ܸߣ������
������ľ�Զ��ʯ�嶼��ĥ����б�£��������������ѡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : "/d/huashan/xiaolu1",
  "southdown" : __DIR__"tl8",
]));

	set("outdoors","huayin");
	setup();
	replace_program(ROOM);
}