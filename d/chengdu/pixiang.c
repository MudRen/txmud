// Room: /wiz/louth/c/pixiang.c

inherit ROOM;

void create()
{
	set("short", "僻巷");
	set("long", @LONG
从这里向西走是万明路。从这里向北是陆佑明家，向南是一
座破旧大院。
LONG
);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"dayuan",
  "west" : __DIR__"wmlu1",
  "north" : __DIR__"chenjia",
]));

	set("outdoors","chengdu");

        set("objects",([
        NPC_DIR"stdnpc/stdnpc_2" : 3,
]));

	setup();
	replace_program(ROOM);
}
