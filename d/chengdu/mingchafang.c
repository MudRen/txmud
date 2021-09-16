// Room: /wiz/louth/c/mingchafang.c

inherit ROOM;

void create()
{
	set("short", "茗茶坊");
	set("long", @LONG
这里是供人品茶闲聊的茗茶坊。茶坊里的摆设简单而不失典
雅，反而更加体现出“茗茶”的气氛。几个喝茶的好友正座在同
一个茶几旁畅谈着，店里的小伙计忙上忙下，起喘吁吁，不过亦
忙的不亦乐乎？这里的门外就是府道街了。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"fdjie2",
]));
        set("objects",([
        __DIR__"npc/fanboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
