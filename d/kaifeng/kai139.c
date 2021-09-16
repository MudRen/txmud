// Room: /u/w/wangs/b/kai139.c

inherit ROOM;

void create()
{
	set("short", "春来福酒楼");
	set("long", @LONG
春来福酒楼是这一带最出名的酒家。单那掌勺的董师傅，据
说原是宫中御厨，只因得罪了管事的太监，被逐出宫来，落身于
此。来往的文人墨客，英雄侠士，多到这个地方会饮。酒楼的对
面是开封府衙门，所以这里一向都很太平，没有人在这里闹事。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai138",
]));

        set("objects",([
        __DIR__"npc/xiaosanzi" : 1,
]));

	setup();
	replace_program(ROOM);
}
