// /d/changan/eroad9 东安大道

inherit ROOM;

void create()
{
        set("short", "东安大道");
        set("long", @LONG
这里是长安城的东安大道，是运送去皇宫的唯一粮道，地上
满是深深的车辙，每天到未时，就会有许多的车辆轰隆隆的由此
经过，而居住在这里的百姓似乎早已是见怪不怪了。这里向西是
内环城路的东环路，向东直通长安城的东门。
LONG
        );

	set("exits", ([
                "east"           : __DIR__"eroad4",
                "west"           : __DIR__"ehroad2",
]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
