// Room: /d/path3/k_h11.c

inherit ROOM;

void create()
{
	set("short", "ɽ���ӵ�");
	set("long", @LONG
����һƬɽ�֣����й�ľ������һ�ۿ������ߡ�������ʱ��
�������죬������ʲô����ܹ��������ֵط�������ҪС��Щ��
����ҧ�˿ɲ������¡��������ͭ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h12",
  "north" : __DIR__"k_h10",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
