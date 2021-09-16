// Room: /d/huashan/qitu2.c / by pian

inherit ROOM;

void create()
{
	set("short", "歧途");
	set("long", @LONG
山势和缓下来，斜阳自西边的山顶露出头来。血红的阳光泻
在连绵的山峰。风轻，云淡，偶尔有一个樵夫，在山林间一现，
唱一两句山歌，又隐没有山林之间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "westup" : __DIR__"qitu1",
  "east" : __DIR__"qitu3",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
