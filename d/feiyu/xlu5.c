// Room: /wiz/louth/a/xlu5.c

inherit ROOM;

void create()
{
	set("short", "小路尽头");
	set("long", @LONG
这是一条曲折的林间小路，路旁是高大的白杨树，几缕阳光
从浓密的树叶间透射而下，一阵微风吹过，树叶沙沙作响。路中
间是块一人多高的大石头。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xlu4",
]));

	set("item_desc",([
	"大石头" : "一块巨大的岩石(rock)。\n",
]));

        set("outdoors","feiyu");
	setup();
}

void init()
{
        add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();

	if(arg != "岩石" && arg != "rock")
		return notify_fail("你要推什么？\n");

	if(query("exits/enter"))
		return notify_fail("岩石已经被推开了。\n");

	if( (me->query("force_factor") < 80) || (me->query("force") < 80) )
                return notify_fail("你用力推了一下岩石，结果岩石纹丝没动。\n");

        message_vision("$N运起内力，大喝一声，推开了岩石。
原来是一个密道的入口。\n",me);

	me->add("force",-40);
	set("exits/enter",__DIR__"shidao1");
	call_out("greeting",5);
	return 1;
}

void greeting()
{
	if(query("exits/enter"))
	{
		write ("岩石慢慢移了回去。\n");
		delete("exits/enter");
	}
}
