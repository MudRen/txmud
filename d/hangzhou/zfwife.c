// Room: /d/hangzhou/zfwife.c

inherit ROOM;

void create()
{
	set("short", "夫人卧房");
	set("long", @LONG
这是杭州知府大人元配吴夫人的卧房，吴夫人本是七省巡抚
吴大人的千金，高廉之所以成为杭州知府也全是靠岳父大人的帮
助。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"zfpath8",
]));

	setup();
	replace_program(ROOM);
}
