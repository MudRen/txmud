// backyard 后院

inherit ROOM;
void create()
{
        set("short", "后院");
        set("long", @LONG
这里是土地庙的后院，四下荒芜，野草丛生，后墙也已经破
损不堪，经常有一些乞丐翻墙进来在此抱头而睡。南边是土地庙。
LONG
        );
	set("exits", ([
                "south"           : __DIR__"badroom",
	]) );
        set("objects",([
                "/d/gaibang/npc/yu":1,
	]));

	set("outdoors","changan");
	setup();
	replace_program(ROOM);
}
