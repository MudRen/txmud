// jiguan.c

inherit ITEM;

private int last = 0;

void create()
{
        set_name("������", ({ "ji guan"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
		set("unit", "��");
		set("long", "������\n");
	}
}

void init()
{
	if( (environment() == this_player()) && !last)
	{
		last = 1;
		remove_call_out("do_lasting");
		call_out("do_lasting",240);
	}
}

void do_lasting()
{
	if(environment())
		tell_object(environment(),"�����ڷŵ�ʱ��̫��������ˡ�\n");
	set("name","��ɵĹ�����");
}
