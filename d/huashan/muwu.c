// Room: /d/huashan/muwu.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "草堂");
        set("long", @LONG
一间简陋的草房，只有一个书架和一张床。书架上零乱地堆
着几本残破的古书。床边的地上是一堆空酒瓶。整个屋里散发出
你也说不清的味道。床头挂着一幅画(hua)。
LONG
);

        set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"zhujian",
]));

	set("item_desc", ([ /* sizeof() == 1 */
	"hua" : WHT"    画上是一个少女在洗头，一手扶盆，一手捋着头发，很是传神。\n
    边上题着一首诗(shi)，前两句笔体婉约，后两句字迹遒劲。\n"NOR,

	"shi":HIC"    十里平湖霜满天，寸寸青丝愁华年，\n
    形单影只望相护，只慕鸳鸯不慕仙。\n"NOR
]));

	setup();
	replace_program(ROOM);
}

