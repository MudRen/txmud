#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"���"NOR, ({"gift"}));
        set_weight(10);
    	set("no_give","ÿ����ֻ��һ�����㶼��ô�󷽣�\n");
    	set("value", 0);
	set("no_steal",1);
	set("no_beg",1);
    	set("no_put",1);
    	set("no_get","ÿ����ֻ��һ������Ҫ��ô̰�ģ�\n");
    	set("no_drop","��ô���Ķ�����Ҳ�ӣ���\n");
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "\n����һ������������һ�н��֣�\n\n                 " + HIY + "Ը��������֣�\n\n                                                  "+HIC MUD_NAME + "��ʦ����"+NOR+"\n\n���滹������ʲô�������ԣ�����Դ�(open)����\n");
                set("unit", "��");
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

	if(arg != "gift"&& arg != "���")
                return notify_fail("��Ҫ��ʲ�᣿\n");
        me->add("potential",1888);
	me->add("combat_exp",8888);
	message_vision(HIG"$N�������"+HIR+"���"+HIG+"����ͻȻ�о��Լ���ʵս�����Ǳ������ˡ�\n"NOR,me);
	destruct(this_object());
	return 1;
}
