inherit ITEM;

void create()
{
        set_name("�ɿ���", ({ "qiao ke li" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ�����˽��ɿ���ร��ܺóԵģ�\n");
                set("unit", "��");
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
	this_player()->add("potential", 5000);
	this_player()->add("food", 200+random(50));
	this_player()->add("water", 200+random(50));
	message_vision("$N�����ɿ����ŵ���� \n$N�о�����ʹ�Լ��������������ˣ�\n", this_player());
	destruct(this_object());
	return 1;
	}
}