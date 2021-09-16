// shu_boss.c
// By Find.

#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("����ѧ", ({ "boss liu", "boss"}) );
	set("title","����ϰ�");
        set("gender", "����" );
        set("age", 45);
        set("long","����ϰ塣\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		BOOK_DIR"luo_book":5,
		BOOK_DIR"guwen_book":5,
		BOOK_DIR"parrybook" : 3,
        ]) );

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = previous_object()) && !is_fighting() )
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	string day_night;
	int time;

	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	if(!userp(ob) && ob->query("is_beggar"))
	{
		message_vision(CYN"$N����$n˵������Ӱ���������⣬�Ͻ���ȥ��\n"NOR,this_object(),ob);
		ob->go_back_direction();
		return;
	}

	if(!is_day())
	{
		sscanf( day_night(),"%s %d",day_night,time);
		say( (time > 480) ? CYN"�Բ��𣬱ɺ��Ѿ������ˣ�"+RANK_D->query_respect(ob)+
			"�����������ɡ�\n"NOR
			: ( (time <= 60) ? CYN"���ϰ�Ц���е�˵����������һ�°ɣ�С�����ϾͿ����ˡ�\n"NOR
			: CYN"���ϰ�˵�����������������ɡ�\n"NOR ) );
		return;
	}
	else
	{
		switch( random(2) )
		{
                case 0:
                        say( CYN"���ϰ����ﹾ���ţ��������лƽ��ݡ����������񡣡���\n"NOR);
                        break;
                case 1:
                        say( CYN"���ϰ�һ����˵������λ" + RANK_D->query_respect(ob)
                                + "���٣�С��������ԣ�����������\n"NOR);
                        break;
		}
	}
}
