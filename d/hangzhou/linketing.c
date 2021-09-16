// Room: /d/hangzhou/linketing.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����ɵĴ󷿼䣬�������һ��̴ľ�����������Ӻ�
���ǽ�Ϲ���һ���ͻ���ɽͼ��������һ�Ź���������ȴ�ǹض�
ү��������Ա�ⲻ�Ǹ������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"linneiyuan",
  "east" : __DIR__"linbookroom",
]));

	set("objects",([
	__DIR__"npc/l_shiye" : 1,
]));

	setup();
	replace_program(ROOM);
}
