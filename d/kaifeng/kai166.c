// Room: /u/w/wangs/b/kai166.c

inherit ROOM;

void create()
{
	set("short", "向阳街");
	set("long", @LONG
这里是个很热闹的街道。街道上挤满了各式各样的人，大多
数人看来都很愉快，因为他们经过一天工作的辛劳，现在正穿着
乾净的衣服，舒服的鞋子，囊中多多少少都有些自节俭的生活中
省下来的钱，所以他们已经可以尽情来享受闲暇的乐趣。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai52",
  "west" : __DIR__"sdoor",
  "east" : __DIR__"kai165",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
