// Room: /wiz/uudd/path2/liroom.c

inherit ROOM;

void create()
{
	set("short", "李记狗肉店");
	set("long", @LONG
这里就是少室山一带有名的李记狗肉店，别看这里店面不
大但是生意可是真够红火的，“老板！给我再来一盘狗肉！”
这种声音此起彼伏。“哎呀”不好！一不留神你的口水流了出
来。你慌忙用手蹭了蹭。然后对周围的人不好意思的笑了笑。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"k_s14",
]));

	setup();
	replace_program(ROOM);
}
