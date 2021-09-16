// /d/changan/eroad4  东安大道

inherit ROOM;

void create()
{
        set("short", "东安大道");
        set("long", @LONG
这里就是长安城的东大街主道，长安的东门，是专门运送供
往皇宫的粮路，出了东门便是运河，由于漕运的发达，所以皇粮
也是每天从这里经过的，这个门，平时来的很少，只在有粮运进
时，才会打开，人们一听到“轰隆隆”的车轮声，便知道又粮运
进来了。由这里向东是长安的东门，向北和向南是连德街，西面
直通皇宫的东门。
LONG
        );

	set("exits", ([
                "north"           : __DIR__"eroad5",
                "west"            : __DIR__"eroad9",
                "east"            : __DIR__"edoor",
                "south"           : __DIR__"eroad3", ]) );
	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
