// by dicky

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"��ϻ��"NOR, ({"box"}));
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
                set("long", "\n����һ��ѩ�׵�ϻ���������һ�н��֣�\n\n                 " + HIY + "Ը��ʥ���ڿ��֣�������֣�\n\n                                                  "+HIC MUD_NAME + "��ʦ����"+NOR+"\n\n���滹������ʲô�������ԣ�����Դ�(open)����\n");
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
	object me,ob;
	me = this_player();

	if(arg != "box"&& arg != "��ϻ��")
                return notify_fail("��Ҫ��ʲ�᣿\n");

	ob = new(__DIR__"rose");
	ob->move(me);
	ob = new(__DIR__"qiaokeli");
	ob->move(me);
	message_vision("$N�������"+HIW+"��ϻ��"+NOR+"��\n�����淢����һ���õ���һ��ʥ�����⡣\n",me);	
	destruct(this_object());
	return 1;
}