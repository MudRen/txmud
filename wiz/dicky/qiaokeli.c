// by dicky

inherit ITEM;

void create()
{
        set_name("圣诞蛋糕", ({ "shengdan dangao","dangao" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一块圣诞节蛋糕喔！很好吃的！\n");
                set("unit", "块");
		set("no_give","每个人只有一块，你都这么大方！\n");
		set("no_steal",1);
		set("no_beg",1);
		set("no_put",1);
		set("no_get","每个人只有一个，不要这么贪心！\n");
	        set("no_drop","这么珍贵的东西你也扔？！\n");

        }
        setup();
}

void init()
{
  add_action("do_eat","eat");
}

int do_eat(string arg)
{
	if(arg = "qiao ke li"||arg = "qkl")
	{
	this_player()->add("max_force", 200+random(50));
	this_player()->add("food", 200+random(50));
	this_player()->add("water", 200+random(50));
	message_vision("$N拿起诞节蛋糕，三下五去二就吃完了。 \n$N感觉到爱使自己的力量又增大了！\n", this_player());
	destruct(this_object());
	return 1;
	}
}

void owner_is_killed()
{
        destruct(this_object());
}



