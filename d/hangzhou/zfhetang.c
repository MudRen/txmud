// Room: /d/hangzhou/zfhetang.c

inherit ROOM;

void create()
{
	set("short", "荷塘");
	set("long", @LONG
你面前是一个小小的荷塘，荷塘的面积不大，但荷花却开的
分外茂盛，低头看看水面，鲤鱼摆尾溅起的涟漪在渐渐的散开，
荷叶上的露水虽着荷叶的摇摆，轻轻的落入水中。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zfpath3",
]));

	setup();
	replace_program(ROOM);
}
