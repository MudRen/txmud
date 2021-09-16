// Room: /d/path5/kch10.c

inherit ROOM;

void create()
{
	set("short", "陡坡");
	set("long", @LONG
你气喘嘘嘘的来到这里，山势更加险恶了。那些突出的石堆
和尖峰，随着光线的幻化而轮流的发出光辉。继续向前走吧。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"kch09",
  "up" : __DIR__"kch11",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "依前面的地形，你徒步还能过去，它们是没戏了。");
	setup();
	replace_program(ROOM);
}
