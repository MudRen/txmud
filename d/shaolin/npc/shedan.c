// shedan.c

inherit ITEM;

void create()
{
	set_name("�߲��ߵ�", ({ "she dan"}) );
        set_weight(50);
        if( clonep() )
	{
		set_default_object(__FILE__);
		call_out("do_decay",300);
	}
        else
	{
		set("unit", "��");
		set("long", "����һ��ī��ɫ���߲��ߵ���\n");
	}
}

protected void do_decay()
{
	object env;

	if(!objectp(env = environment()))
	{
		destruct(this_object());
		return;
	}
	tell_object(env,sprintf("%s������ʼ�����ˡ�\n",name()));
	set("name","���õ��߲��ߵ�");
	set("long", "����һ�����õ��߲��ߵ�����ɢ���Ŵ̱ǵĶ����\n");
}
