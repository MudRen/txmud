// huandan.c
// ����1/4��������1/2������

// Find.

inherit ITEM;

void create()
{
	set_name("�󻹵�", ({ "huan dan", "dan" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ž�����ҩ�����ƵĲ�ҩ��\n");
		set("value", 2000);
	}
}

void init()
{
	add_action("do_eat",({ "eat","fu" }));
}

int do_eat(string arg)
{
	object me = this_player();
	int max_f,max_k,force,kee;

	if( !arg || !id(arg) )
		return 0;

	if(environment() != me)
		return 0;

	write("�����һ�Ŵ󻹵���ֻ����������ˬ��\n");

	max_f = me->query("max_force");
	force = me->query("force");
	max_k = me->query("max_kee");
	kee = me->query("kee");

	me->set("force",(force+to_int(max_f/4) >= max_f)?max_f:force+to_int(max_f/4));
	me->set("kee",(kee+to_int(max_k/2) >= max_k)?max_k:kee+to_int(max_k/2));
	destruct(this_object());
	return 1;
}