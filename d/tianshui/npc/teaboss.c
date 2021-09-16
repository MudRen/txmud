// /d/tianshui/npc/tea boss.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("��ʦ", ({ "tea boss","boss" }) );
        set("gender", "����" );
        set("age", 39);
        set("long","��ʦ��������һ�������������æ�ţ�����ʱ�Ϳ��˴��к���\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
        set("vendor_goods", ([
		FOOD_DIR"chicken_leg" : -1,
		LIQUID_DIR"kettle" : -1,
        ]) );
        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

	::init();
        if( living(ob = previous_object()) && !is_fighting() )
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
		message_vision(CYN"$N����$n�������ⲻ�������ĵط����Ͻ�����\n"NOR,this_object(),ob);
		ob->go_back_direction();
	}

	if(!is_day())
	{
		sscanf( day_night(),"%s %d",day_night,time);
		say( (time > 480) ? CYN"��ô����죬С���Ѿ������ˣ�"+RANK_D->query_respect(ob)+
			"�����������ɡ�\n"NOR
			: ( (time <= 60) ? CYN"��ʦ��ͷ���������Ͼ�Ҫ�����ˣ���λ�͹����һ�°ɡ�\n"NOR
			: CYN"��ʦ˯�����ʵ�˵����С�껹û�п��ţ��������������ɡ�\n"NOR ) );
		return;
	}
	else
	{
		switch( random(2) )
		{
                case 0:
                        say( CYN"��ʦЦ�����˵������ӭ���٣�С����������ȫ����������\n"NOR);
                        break;
                case 1:
                        say( CYN"��ʦһ����˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n"NOR);
                        break;
		}
	}
}