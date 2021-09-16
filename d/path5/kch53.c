// Room: /d/path5/kch53.c

inherit ROOM;

void create()
{
	set("short", "盐亭");
	set("long", @LONG
一个小亭子坐落一边，这里就是盐亭了。据说是从前盐枭从
海边城市向这里贩盐时修建的，从此后过往的行人就有地方休息
了。亭子边上坚着一个牌子(pai)。
LONG
	);
	set("item_desc",([
          "牌子":"
	northwest    青城山
	south        成都
\n",
	"pai":"
	northwest    青城山
	south        成都
\n",
]));

	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kch54",
  "northwest" : __DIR__"kch52",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
