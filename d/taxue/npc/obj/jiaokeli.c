inherit ITEM;

void create()
{
        set_name("巧克力", ({ "qiao ke li" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一块情人节巧克力喔！很好吃的！\n");
                set("unit", "块");
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
	this_player()->add("potential", 5000);
	this_player()->add("food", 200+random(50));
	this_player()->add("water", 200+random(50));
	message_vision("$N拿起巧克力放到嘴里。 \n$N感觉到爱使自己的力量又增大了！\n", this_player());
	destruct(this_object());
	return 1;
	}
}