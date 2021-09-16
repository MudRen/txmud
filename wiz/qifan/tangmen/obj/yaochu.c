#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_wayao", "dig");
}

void create()
{
	set_name("ҩ��", ({"yao chu", "chu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_drop","��Ҫ�Ҷ����ⶫ�����˻�ʹ�ģ�\n");
		set("no_put",1);
		set("long", "����һ�Ѻ��ص�ҩ�����������������ҩ��dig yao����\n");
		set("value", 5000);
	}
	setup();
}

int do_wayao(string arg)
{       object ob;
        object me=this_player();
        if (me->is_busy()||me->query_temp("pending/exercising")) return notify_fail("��������æ���ء�\n");
        if (!arg||arg!="yao") return notify_fail("��Ҫ��ʲô�أ���\n");
        if ((me->query("sen") < 20)) return notify_fail("��ľ������ܼ��У�����Ҳ�ǰ��ڣ�\n");
        if (me->query("kee") < 40 ) return notify_fail("��̫���ˣ���ô���ò������ҩ����\n");
        if (present("zhengui yaocai", environment(this_object()))||present("putong yaocai",environment(this_object()))) return notify_fail("��֪��,���Ѿ��ڵ�ҩ�ˣ�\n");
        if(environment(this_object()) != me)  return notify_fail("�����ڿ������ڰɣ�\n");
        if (environment(me)->query_temp("wayao1"))
        {
        me->start_busy(random(3)+1);
        message_vision("$N�Ӷ�ҩ�������ꡢ���ꡱ���ڵ�����������,�ƺ�����ʲô������\n",me);
        me->add("kee",-10);
        me->add("sen",-20);
            if(random(7)<3)
      {
        message_vision(YEL"$N���˰��죬���ڰ��ǿ�ҩ��С������ؾ��˳�����\n"NOR,me);
        new(__DIR__"obj/yaocai")->move(me);
        environment(me)->add_temp("wayao1",-1);
        destruct(this_object());
        me->start_busy(1);
      }
      return 1;
   }
      else
   	if (environment(me)->query_temp("wayao2"))
        {
        me->start_busy(1+random(4));
        message_vision(CYN"$N�Ӷ�ҩ����ʼ�ڵ�������������\n"NOR,me);
        me->add("kee",-20);
        me->add("sen",-30);
             if(random(7)<4)
      {
        message_vision(YEL"$N���˰��죬���ڰ��ǿ�ҩ��С������ؾ��˳�����\n"NOR,me);
        new(__DIR__"obj/yaocai")->move(me);
        environment(me)->add_temp("wayao2",-1);
        destruct(this_object());
        me->start_busy(1);
      }
       	return 1;
    }
      return notify_fail("����ʲô��û��,ԭ�����㿴�����ۡ�\n");
}