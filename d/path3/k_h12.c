// Room: /d/path3/k_h12.c

inherit ROOM;

void create()
{
	set("short", "铜陵");
	set("long", @LONG
这里就是铜陵，是江北通往江南的一条要道。路的东侧有一
家正在修建的小屋，看来是有人准备在此开间小店。路的北面是
一眼看不到头的树林，路南立着一个牌子(pai)。
LONG
	);
        set("item_desc",([
	"pai":"
	north        徐州镇
	south        仙人渡
	west         驻马店
\n",
	"牌子":"
	north        徐州镇
	south        仙人渡
	west         驻马店
\n",
]));
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"cross9",
  "south" : __DIR__"k_h13",
  "north" : __DIR__"k_h11",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
