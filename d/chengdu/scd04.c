// Room: /d/chengdu/scd04.c

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
  "north" : __DIR__"scd03",
  "southwest" : "/d/tangmen/lcd01",
]));

	set("outdoors", "chengdu");

	setup();
	replace_program(ROOM);
}
