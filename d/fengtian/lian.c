// Room: /d/fengtian/lian.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
������һ��Ҫ�����䳡�ˣ��Ͼ����佫����ķ���������
��������ʮ���ֱ��������������λεģ�����ʱ�������ﳿ����
���ҽ���������ǹ����ͷ���������䡣
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jjf4",
]));

        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
