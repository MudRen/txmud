// Room: /d/changan/jinghu.c

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
�����Ǿ�����������С��������ˮ�峺���ף������ֵĴ�
����һ����Ȼ�ľ���������������������ÿ�������������񣬲�
֪�����˶�������ɧ�������ﷺ�ۺ�����ʫ������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"sroad5",
  "north" : __DIR__"hu_bank",
]));

	set("objects",([
	__DIR__"npc/juzi" : 1,
]));

	set("outdoors","changan");
	setup();
	replace_program(ROOM);
}
