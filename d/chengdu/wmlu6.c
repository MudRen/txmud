// Room: /wiz/louth/c/wmlu6.c

inherit ROOM;

void create()
{
	set("short", "万明路");
	set("long", @LONG
这里是成都的万明路。向北是一家私宅，门口摆着两个小石
狮子，看样子是个做过官的乡绅。东西则可以贯穿整个万明路。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wmlu7",
  "east" : __DIR__"wmlu5",
]));

	set("outdoors","chengdu");

        set("objects",([
        NPC_DIR"stdnpc/stdnpc_3" : 3,
]));

	setup();
	replace_program(ROOM);
}
