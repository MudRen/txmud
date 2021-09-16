#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
这里是宽敞干燥的大山洞，四周的石壁凿的十分平整，上面
插着几只点燃的火把，地上铺着细细的沙子，踩上去格外舒适。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shandong3",
]));
        set("item_desc",([
        "石壁" : "一面光秃秃的石壁，上边镶着一把不知名的宝剑，只露出了剑柄在外边。\n",
]));
	setup();
}

void init()
{
	add_action("do_get",({ "pull","ba" }));
}

int do_get (string arg)
{
	object me = this_player(),ob;

	if (arg != "sword" && arg != "剑")
		return 0;

	ob = new(__DIR__"obj/windsword");
	if(!ob->valid_clone())
	{
		destruct(ob);
		return notify_fail("石壁上的宝剑已经被人拿走了。\n");
	}

	if(me->query("class") != "rain")
	{
		destruct(ob);
		return notify_fail("你试着拔了两下这把剑，但是毫无反应。\n");
	}

	if(me->query_skill("unarmed") < 120 || me->query("str") < 40)
	{
		destruct(ob);
		return notify_fail("你的臂力还拔不动这把剑。\n");
	}

	if(me->query("force_factor") < 100 || me->query("force") < 100)
	{
		destruct(ob);
		return notify_fail("你试着拔了拔宝剑，结果纹丝不动。\n");
	}

	message_vision(HIC"$N运起内力，胳膊上青筋暴起，大喝一声，拔出了镶在石壁上的宝剑。\n"NOR,me);
	me->add("force",-100);
	ob->move(me);
	return 1;
}
