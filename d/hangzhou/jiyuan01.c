// Room: /d/hangzhou/jiyuan01.c

inherit ROOM;

void create()
{
	set("short", "�ż����");
	set("long", @LONG
����ͨ����¥�ĺ�������������¥�������������
�����͵ĳ������ܹ�һ̽���Ŀ��˷Ǹ�����Ѱ���˵��Ǹ���
û��һ�׷���ġ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jiyuan",
  "east" : __DIR__"jiyuan02",
]));

	setup();
	replace_program(ROOM);
}
