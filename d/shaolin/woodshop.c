// Room: /wiz/uudd/path2/woodshop.c

inherit ROOM;

void create()
{
	set("short", "木匠铺");
	set("long", @LONG
这里是一间很普通的木匠铺，一个老木匠正在无聊的刻着一
个小木人，看起来他的生意不是很好，他看见你走进来，赶忙站
起来对你点了一下头，并非常礼貌的问：“你想买点家具吗？。”
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"k_s15",
]));

	setup();
	replace_program(ROOM);
}
