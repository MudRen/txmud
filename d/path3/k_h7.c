// Room: /d/path3/k_h7.c

inherit ROOM;

void create()
{
	set("short", "ɽ���ӵ�");
	set("long", @LONG
����һƬɽ�֣����й�ľ������һ�ۿ������ߡ�������ʱ��
�������죬������ʲô����ܹ����㲻�ɵ����С�ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h8",
  "north" : __DIR__"k_h6",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
