// Room: /d/changan/sroad2.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ﳤ���ǵ��ϴ�֣�����һ�����ǽ����������Ǵ��ʽ��
�յ����ڡ���פ���ڴˣ��ῴ�����̾���������ڴ���Ū����
�Ŀ��ұ��졣��������������ϴ���ϡ������Ǿ����������ļ�
�÷��̡�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "changan");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"sroad3",
  "south" : __DIR__"caifeng",
  "west" : __DIR__"sroad1",
]));

	set("objects",([
	__DIR__"npc/yiren" : 1,
	__DIR__"npc/yi_girl" : 1,
]));

	setup();
	replace_program(ROOM);
}
