// lingzhi.c ��ת��֥��   by pian huashan
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(WHT"��ת��֥��"NOR, ({"jiu zhuan lingzhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "֦");
		set("long", WHT"    һ֦��ת��֥�ݣ�������ѵ�һ�����������������Ե�ʲô�ء�\n"NOR);
		set("value", 500);
	}
	setup();
}

int do_eat(string arg)
{
      object me;
      me=this_player();
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

      me->set("kee", me->query("max_kee"));  
      me->set("gin", me->query("max_gin"));
      me->set("sen", me->query("max_sen"));
      me->set("eff_kee", me->query("max_kee"));
      me->set("eff_gin", me->query("max_gin"));
      me->set("eff_sen", me->query("max_sen"));
      me->set("max_force",me->query("max_force")+100);

	message_vision("$N����˫��һ�����¾�ת��֥�ݣ�\n
      ��ʱ��$N�۾�һ����ֻ����ȫ������˻��� !\n", this_player());
	destruct(this_object());
	return 1;
}

