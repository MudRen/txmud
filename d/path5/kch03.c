// Room: /d/path5/kch03.c

inherit ROOM;

void create()
{
	set("short", "岔路口");
	set("long", @LONG
你走到一个岔路口，不禁停下了脚步。调整一下吧，在这种
山区走路是最累的了。你四处张望，一时分不清了方向。在路边
的水沟边，斜插着一个牌子(pai)。
LONG
	);
	set("item_desc",([
          "牌子":"
	north        南坪镇
	south        五霸山
	east         秀水河岸
	west         澜沧江
\n",
          "pai":"
	north        南坪镇
	south        五霸山
	east         秀水河岸
	west         澜沧江
\n",
]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kch04",
  "west" : __DIR__"w01",
  "eastdown" : __DIR__"e01",
  "north" : __DIR__"kch02",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
