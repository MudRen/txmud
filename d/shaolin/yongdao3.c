// Room: /d/shaolin/yongdao3.c

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
�����������µ�һ����ʯ�����������������˺�������
ʹ������Ҳ�ò���ˬ�������������Ǿ������ܾõĹ�ʫ������ͨ
�Ĵ���������ľ����������Ϻ�������ʯ���������ǽ���
Ժ�����ǲؾ���
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yongdao2",
  "north" : __DIR__"yongdao4",
  "east" : __DIR__"cangjing1",
  "west" : __DIR__"jielv",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
