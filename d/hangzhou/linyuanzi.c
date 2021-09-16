// Room: /d/hangzhou/linyuanzi.c

inherit ROOM;

void create()
{
	set("short", "�쾮");
	set("long", @LONG
�ƹ�Ӱ��ǽ������վ����Ա�⸮�ڵ�ǰԺ�ټ���Ժ��ȫ
������ʯ�̵أ�����һ����Ⱦ��������һ��Сƽ������������
һ����Ȧ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"linhorse",
  "west" : __DIR__"linhouse",
  "east" : __DIR__"linneiyuan",
  "north" : __DIR__"linchaifang",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
