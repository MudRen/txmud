// Room: /d/path5/e06.c

inherit ROOM;

void create()
{
	set("short", "河边草地");
	set("long", @LONG
这是秀水河的西岸，岸上的青草地上正飞舞着几只蝴蝶。河
水湍湍向前方奔去，虽然水不太深，水流却着实很急。要过河看
来只有找船家帮忙了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"e05",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
