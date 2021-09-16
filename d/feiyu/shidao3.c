// shidao3.c

inherit ROOM;

void create()
{
        set("short", "石道");
        set("long", @LONG
这是一条山间小路，路边长满了蒿草，显见这里很少有人来，
迎面是一面光滑的石壁。
LONG
        );

        set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"shidao2",
]));
	set("outdoors","feiyu");
        setup();
}

void init()
{
        add_action("do_break","break");
}

int do_break(string arg)
{
        object me = this_player();

	if(arg != "石壁" && arg !=  "wall")
		return notify_fail("你要击碎什么?\n");

	if(me->query("force") < 100)
		return notify_fail("你的内力还没有调息过来,不能连续运功.\n");

        if (me->query("kee") <100)
                return notify_fail("你太累了,还是先休息一下吧.\n");

        if (me->query("force_factor") < 100)
                return notify_fail("你不运用内力是击不碎这面石壁的.\n");

	if(query("exits/enter"))
		return notify_fail("这块石壁已经被人击碎了.\n");

        message_vision("$N大喝一声,运起内力,对着石壁击去。。。\n只听见一声巨响,石壁被击破了一个缺口。\n$N也累的气喘吁吁。\n",me);

	me->receive_damage("kee",100,"tire");
        me->add("force",-100);

	set("exits/enter",__DIR__"shidao9");
	return 1;
}
