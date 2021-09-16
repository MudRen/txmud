// Room: /wiz/louth/c/wwdao1.c

inherit ROOM;

void create()
{
	set("short", "武王道");
	set("long", @LONG
这是成都的武王道。由这里向西就是防具店。向东是回春堂。
向北是万明路。向南可以走到武王道的尽头。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"fangjvdian",
  "south" : __DIR__"wwdao2",
  "east" : __DIR__"huichuntang",
  "north" : __DIR__"wmlu8",
]));

	set("outdoors","chengdu");

        set("objects",([
        NPC_DIR"stdnpc/stdnpc_1" : 3,
]));

	setup();
	replace_program(ROOM);
}
