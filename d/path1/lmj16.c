// Room: /d/path1/lmj16.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��ɽ�ߵ�С����һֱ�򱱾��ܵ�����ɽ�������߹�һ
���������С�����͵���¹����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"lmj15",
  "northup" : __DIR__"lmj17",
]));
	set("outdoors", "path1");

	set("objects",([
	RIDE_DIR"w_luozi" : 1,
]));

	setup();
	replace_program(ROOM);
}
