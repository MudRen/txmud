// Room: /d/path3/k_s21.c

inherit ROOM;

void create()
{
	set("short", "长江环曲");
	set("long", @LONG
这里位于长江中游北岸，岸边向内陆弯进了一块，湍湍的江
水流到此处也放慢了速度。你仔细看去，只见不少鱼儿虾蟹在河
水中游来游去，这可是正宗新鲜的长江江蟹，不如钓(fish)几只
来解解谗。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"k_s20",
    "west" : __DIR__"k_s22",
]));
        set("cannot_build_home", 1);
        set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
