// Room: /d/path3/k_h38.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
����һ������ʯ�̳ɵĹٵ�����·�������������Ե�ʮ����
�֡�����߱߿���Ҳ˵�����ǲ�������Щʲô��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h39",
  "north" : __DIR__"k_h37",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
