// Room: /wiz/uudd/path2/minjv01.c

inherit ROOM;

void create()
{
	set("short", "农居");
	set("long", @LONG
屋子里光线不是很好，空气也有点让人不好受，好象是大蒜
什么的一种味道，你不禁皱了皱鼻子，环顾四周，几乎没有什么
家具，一张木桌摆在屋子的中央，一个小木柜立在墙角，旁边有
一张破木床，看起来已经用不了多久了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"k_s11",
]));

	setup();
	replace_program(ROOM);
}
