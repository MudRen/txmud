// Room: /d/shaolin/wenshu.c

inherit ROOM;

void create()
{
	set("short", "文殊殿");
	set("long", @LONG
这里是少林寺的文殊殿，一进大殿你看到正中供奉着的，正
是文殊广法菩萨。只见他端从在青狮上的一个莲花宝座上，无比
慈祥，这个殿又有人称之为大智殿，是因为文殊菩萨又称大智菩
萨的缘故。从这里往西是后院的过道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"rroad4",
]));

	set("objects", ([
	__DIR__"npc/huizheng" : 1,
]));

	setup();
	replace_program(ROOM);
}
