// Room: /d/chengdu/scd03.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
����һ������ʯ���̳ɵĴ�·��·�������������˺ܶ࣬��
�����С�����ؽֽ��������ֳ�һ�鷱���ľ����ɴ�������
�͵��ɶ������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"scd04",
  "north" : __DIR__"scd02",
]));

	set("outdoors", "chengdu");

	setup();
	replace_program(ROOM);
}
