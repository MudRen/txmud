// Room: /u/w/wangs/a/yu72.c

inherit ROOM;

void create()
{
	set("short", "悬崖底");
	set("long", @LONG
你的面前是一座笔直的山峰，高若千丈，峰顶在云雾中
隐约可见，山峰光秃秃的，毫无置手足处。你已经走到了崖
底的尽头，只有一片灌木横在你的面前。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"yu69",
]));
        set("item_desc",([
        "灌木" : "一片浓密的灌木林，隐约中能看见一小部分有被兵器砍过的痕迹。\n",
        "wood" : "一片浓密的灌木林，隐约中能看见一小部分有被兵器砍过的痕迹。。\n",
]));
	set("outdoors","feiyu");

	setup();
}

void init()
{
	add_action("do_kan","kan");
}

int do_kan(string arg)
{
	object me,ob,obj;

	me = this_player();

	if(arg != "灌木" && arg !="wood")
	{
		write("你要砍什么？\n");
		return 1;
	}

	if(!obj = me->query_temp("weapon"))
	{
		write("你要拿什么砍？\n");
		return 1;
	}

	if( (me->query("class") == "rain") && (random(20) > me->query("kar")) )
	{
		ob=new(__DIR__"obj/fengyuesword");
		if(!ob->valid_clone())
			destruct(ob);
			
		else
		{
			ob->move(this_object());
			message_vision("$N对着灌木林奋力砍去，感觉砍到了一个硬邦邦的东西。\n仔细一看，地上有一把锋利的宝剑。\n",me);
			return 1;
		}
	}
	message_vision("$N对着灌木林奋力砍去，结果砍倒了一片灌木。\n",me);
	me->start_busy(2);
	return 1;
}
