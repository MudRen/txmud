// Room: /wiz/louth/c/wmlu5.c

inherit ROOM;

void create()
{
	set("short", "万明路");
	set("long", @LONG
这里是成都的万明路。由这里向南就是悦来客栈。往北是一
家水果店。东西方向则可以贯穿整个万明路。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yuelaikezhan",
  "west" : __DIR__"wmlu6",
  "east" : __DIR__"shizi1",
  "north" : __DIR__"shuiguodian",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
