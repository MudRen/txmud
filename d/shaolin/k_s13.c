// Room: /wiz/uudd/path2/k_s13.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条用小石子铺成的小路，走起来有点硌脚，你走起路
来有一些不自然，路旁有一些当地村民嘻嘻哈哈的对你指指点点。
你不屑一顾，心想：“哼！乡下人。”
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s12",
  "north" : __DIR__"k_s14",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
