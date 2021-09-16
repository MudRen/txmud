// shulin.c
// by dicky

inherit ROOM;

void create()
{
    set("short", "松林");
	set("long", @LONG
这是后山的一片茂密的松林中，四周静悄悄的。阴森森的十分怕人，
一阵风吹来，你不禁一抖。
LONG);

	set("outdoors", "taxue");

	set("exits",([
             "northwest" : __DIR__"shulin1",
             "northeast" : __DIR__"shulin3",
             "south" : __DIR__"xiaolu",
	]));

	setup();
	replace_program(ROOM);

}
