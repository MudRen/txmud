// Room: /d/shaolin/lroad2.c

inherit ROOM;

void create()
{
	set("short", "ǰԺ����");
	set("long", @LONG
�����������µ�ǰԺ�������������ִ���ʱ������������
���������㲻����̾�������¹�Ȼ��һ�����е�����֮�ء�����
û��Զ��һ��С��ɽ��������������Ů�����޵ġ�����������
���㳡�������ǹ�����������һ�����䳡��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lroad1",
  "west" : __DIR__"lwc_w",
  "north" : __DIR__"w_square",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
