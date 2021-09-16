
inherit ROOM;
void create()
{
        set("short", "华瑞街");
        set("long", @LONG
这是南大街的最东面，也是全长安城的东南角，这样偏僻的
地方，人们很少光顾这里。只是偶尔有三三两两的巡捕会路过这
里，如果没什么事，这样的地方最好还是少来为妙。西边是华瑞
街，向北便是连德街了。
LONG
        );

	set("exits", ([
	"west" : __DIR__"sroad7",
	"north" : __DIR__"eroad1",
	"east" : __DIR__"selling_room",
]) );
	set("outdoors","changan");

	set("objects",([
	__DIR__"npc/yao_fanzi" : 1,
]));

        setup();

	replace_program(ROOM);
}
