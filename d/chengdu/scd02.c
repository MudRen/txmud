// Room: /d/chengdu/scd02.c

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
  "south" : __DIR__"scd03",
  "north" : __DIR__"scd01",
]));

	set("outdoors", "chengdu");

	setup();
	replace_program(ROOM);
}
