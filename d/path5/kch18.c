// Room: /d/path5/kch18.c

inherit ROOM;

void create()
{
	set("short", "山溪");
	set("long", @LONG
你来到这里，四周一片绿色的树林，风儿吹过，传来阵阵声
响。忽然听到流水的声音，仔细一看，清澈的山泉正顺着山势流
淌，在路边一块岩石后洼处汇聚成一潭。打点水喝吧，那可是纯
天然。石边横放着一个牌子(pai)。
LONG
	);
	set("item_desc",([
	"pai":"
	east         青城山
	northup      五霸山
\n",
	"牌子":"
	east         青城山
	northup      五霸山
\n",
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"kch19",
  "northup" : __DIR__"kch17",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "依前面的地形，你徒步还能过去，它们是没戏了。");
	setup();
	replace_program(ROOM);
}
