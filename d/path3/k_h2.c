// Room: /d/path3/k_h2.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ�������̳ɵĹٵ���·�������˲��ٵ���ˮ�����⼤
��̫��ĳ������ɴ���������Զ�����ǿ��⸮�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"k_h1",
  "east" : __DIR__"k_h3",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
