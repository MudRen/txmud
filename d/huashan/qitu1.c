// Room: /d/huashan/qitu.c / by pian

inherit ROOM;

void create()
{
	set("short", "歧途");
	set("long", @LONG
茂密的树林间隐露出一条小路。四周除了陡峭的山林看不到
任何东西。这条小路极是幽静，连鸟虫都不再鸣唱，真让人有点
落寞的伤感。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"xiaolu4",
  "eastdown" : __DIR__"qitu2",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
