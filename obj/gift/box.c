// by dicky

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"白匣子"NOR, ({"box"}));
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
                set("long", "\n这是一个雪白的匣子上面刻着一行金字：\n\n                 " + HIY + "愿你圣诞节快乐！新年快乐！\n\n                                                  "+HIC MUD_NAME + "巫师组上"+NOR+"\n\n里面还有像还有什么东西可以，你可以打开(open)它。\n");
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
	object me,ob;
	me = this_player();

	if(arg != "box"&& arg != "白匣子")
                return notify_fail("你要打开什麽？\n");

	ob = new(__DIR__"rose");
	ob->move(me);
	ob = new(__DIR__"dangao");
	ob->move(me);
	message_vision("$N轻轻打开了"+HIW+"白匣子"+NOR+"。\n在里面发现了一朵红玫瑰和一块圣诞蛋糕。\n",me);	
	destruct(this_object());
	return 1;
}