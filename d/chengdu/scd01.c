// Room: /d/chengdu/scd01.c

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
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"out_chengdu_s",
  "south" : __DIR__"scd02",
]));

	set("outdoors", "chengdu");

	setup();
	replace_program(ROOM);
}
