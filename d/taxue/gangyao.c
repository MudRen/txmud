// gangyao.c
// by dicky

inherit ROOM;

void create()
{
	set("short","缸窑");
        set("long",@LONG
来到这里，除了一阵浓浓的酒香外，由于空气不流通还感到一丝丝头
晕。透过墙壁上的烛光，依稀可以看到一个个突起的小土包。上面都插着
牌子。原来这里就是埋酒的地方。
LONG);

	set("exits",([
		"up" : __DIR__"zaofang",
	]));

	setup();
	replace_program(ROOM);
}
