// nroad2  麒祥街

inherit ROOM;

void create()
{
        set("short", "麒祥街");
        set("long", @LONG
这里是长安城的北大街的最东面，这里好像并不太热闹，给
人一种肃杀的感觉。街上偶尔匆匆走过几个带兵器的武者，一般
的老百姓从来不到这个地方来。南面是武林闻名德威镖局，门口
站着两个舔胸叠肚的壮汉，进出的人都是一脸神秘。
LONG
        );

	set("exits", ([
                "west"            : __DIR__"nroad3",
                "east"            : __DIR__"nroad1",
                "south"           : __DIR__"convoy",
]) );

	set("outdoors","changan");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_2" : 3,
]));

        setup();
	replace_program(ROOM);
}
