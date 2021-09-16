#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"红包"NOR, ({"gift"}));
        set_weight(10);
    	set("no_give","每个人只有一个，你都这么大方！\n");
    	set("value", 0);
	set("no_steal",1);
	set("no_beg",1);
    	set("no_put",1);
    	set("no_get","每个人只有一个，不要这么贪心！\n");
    	set("no_drop","这么珍贵的东西你也扔？！\n");
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "\n这是一个红包上面刻着一行金字：\n\n                 " + HIY + "愿你新年快乐！\n\n                                                  "+HIC MUD_NAME + "巫师组上"+NOR+"\n\n里面还有像还有什么东西可以，你可以打开(open)它。\n");
                set("unit", "个");
        }
	setup();
}

void init()
{
  add_action("do_open","open");
}

int do_open(string arg)
{
	object me;
	me = this_player();

	if(arg != "gift"&& arg != "红包")
                return notify_fail("你要打开什麽？\n");
        me->add("potential",10000);
	message_vision("$N轻轻打开了"+HIR+"红包"+NOR+"。\n你突然感觉自己的潜能提高了。\n",me);
	destruct(this_object());
	return 1;
}