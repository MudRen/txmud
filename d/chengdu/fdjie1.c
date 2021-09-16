// Room: /wiz/louth/c/fdjie1.c

inherit ROOM;

void create()
{
	set("short", "府道街");
	set("long", @LONG
这里是成都府道街。向西走是成都的竹艺斋。南北方向可以
贯穿整个成都东面的府道街。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jguanlu8",
  "north" : __DIR__"fdjie2",
]));
        set("objects",([
        __DIR__"npc/luren" : 2,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
