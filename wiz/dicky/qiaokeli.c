// by dicky

inherit ITEM;

void create()
{
        set_name("ʥ������", ({ "shengdan dangao","dangao" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ʥ���ڵ���ร��ܺóԵģ�\n");
                set("unit", "��");
		set("no_give","ÿ����ֻ��һ�飬�㶼��ô�󷽣�\n");
		set("no_steal",1);
		set("no_beg",1);
		set("no_put",1);
		set("no_get","ÿ����ֻ��һ������Ҫ��ô̰�ģ�\n");
	        set("no_drop","��ô���Ķ�����Ҳ�ӣ���\n");

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
	message_vision("$N���𵮽ڵ��⣬������ȥ���ͳ����ˡ� \n$N�о�����ʹ�Լ��������������ˣ�\n", this_player());
	destruct(this_object());
	return 1;
	}
}

void owner_is_killed()
{
        destruct(this_object());
}



