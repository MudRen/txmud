// Room: /d/path1/cc_tch18.c

inherit ROOM;

void create()
{
	set("short", "ɳ·");
	set("long", @LONG
�ߵ�������Ѿ���������ˣ����˷�ɳ�;�ʯ����ʲôҲ
����������Զ�ĵ��ϣ�ɢ����һЩʬ�ǣ���֪������ʲô��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"cc_tch17",
  "west" : __DIR__"cc_tch19",
]));
	set("outdoors", "path1");

	set("objects",([
	RIDE_DIR"w_horse" : 1,
]));

	setup();
	replace_program(ROOM);
}
