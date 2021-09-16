// Room: /d/path5/kch19.c

inherit ROOM;

void create()
{
	set("short", "青城山脚");
	set("long", @LONG
你已来到了青城山的脚下，蜿蜒的山路边长着许多小花小草。
放眼看去，只见一遍绿色的波浪此起彼伏。你被大自然的美景陶
醉了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"kch20",
  "west" : __DIR__"kch18",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "依前面的地形，你徒步还能过去，它们是没戏了。");
	setup();
	replace_program(ROOM);
}
