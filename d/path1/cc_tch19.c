// Room: /d/path1/cc_tch19.c

inherit ROOM;

void create()
{
	set("short", "ɳ·");
	set("long", @LONG
�ߵ�������Ѿ���������ˣ����˷�ɳ�;�ʯ����ʲôҲ
����������Զ�ĵ��ϣ�ɢ����һЩʬ�ǣ���֪������ʲô����ɫ
������������ż�ֻͺӥ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cc_tch20",
  "east" : __DIR__"cc_tch18",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
