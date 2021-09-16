// Room: /wiz/louth/c/baozipu.c

inherit ROOM;

void create()
{
	set("short", "包子铺");
	set("long", @LONG
这里是成都北面的包子铺。这里的包子可谓红透了大江南北。
韩包子、龙眼包子不但味道可口，而且外观和色泽都可以说的上
是御善精品！不少的达官贵人每年都要来成都的包子铺吃一吃这
天下难得一食的御善包。出门就是万明路了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wmlu3",
]));
        set("objects",([
        __DIR__"npc/dengboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
