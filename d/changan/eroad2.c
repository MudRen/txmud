// Room: /d/changan/eroad2.c

inherit ROOM;

void create()
{
	set("short", "���½�");
	set("long", @LONG
�����ǳ����ǵĶ���֣����������٣��ǳǶ��ȽϷ����ĵ�
�Σ�������������ؤ������Ŀ���·�ߡ����½��д��������졣
�����Ǿ�������ҩ��-������ҩ����
LONG
	);
	set("outdoors", "changan");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"yaofang",
  "south" : __DIR__"eroad1",
  "north" : __DIR__"eroad3",
]));

	setup();
	replace_program(ROOM);
}
