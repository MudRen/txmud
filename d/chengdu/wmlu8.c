// Room: /wiz/louth/c/wmlu8.c

inherit ROOM;

void create()
{
	set("short", "万明路");
	set("long", @LONG
这里是成都的万明路。由这里向西就是一做地主家的豪宅。
往东可以横贯整个万明路。南边是武王道。
LONG
);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"wwdao1",
  "west" : __DIR__"haozhai",
  "east" : __DIR__"wmlu7",
]));

	set("objects",([
	NPC_DIR"xunpu" : 2,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
