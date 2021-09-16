// Room: /wiz/louth/c/wmlu3.c

inherit ROOM;

void create()
{
	set("short", "万明路");
	set("long", @LONG
这里是成都的万明路。由这里向南就是包子铺。向北向南就
是凉粉店。东西方向则可以贯穿整个万明路。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wmlu4",
  "east" : __DIR__"wmlu2",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
