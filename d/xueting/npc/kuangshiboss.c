// kuangshiboss.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("��ʯ��", ({ "kuangshi boss" }) );
//	set("title","    ");
        set("gender", "����" );
        set("age", 42);
        set("long","����ʲô��ʯ�������Ͷ��ˡ�\n");
        set("combat_exp", 50);
        set("sell_all_day",1);
        set("attitude", "friendly");
        set("vendor_goods", ([
		"/d/obj/kuangshi/qingtong_stone" : -1,
		"/d/obj/kuangshi/lvkuang_stone"  : -1,
		"/d/obj/kuangshi/zikuang_stone"  : -1,
		"/d/obj/kuangshi/hongkuang_stone"  : 20,
		"/d/obj/tanhuo/mutan"  : -1,
		"/d/obj/kuangshi/wujin_stone"  : 0,
		"/d/obj/kuangshi/xuantie_stone"  : 0,
		"/obj/mine/sz_gao": -1,
		"/d/obj/tool/kaishanfu": -1,
		
        ]) );

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
/*

void init()
{
        object ob;

	::init();
        if( living(ob = previous_object()) && !is_fighting() && !wizardp(ob))
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
		message_vision(CYN"$N����$n�������ⲻ�������ĵط�����ȥ!\n"NOR,this_object(),ob);
		ob->go_back_direction();
	}

	if(!is_day())
	{
		sscanf( day_night(),"%s %d",day_night,time);
		say( (time > 480) ? CYN"��ô����죬С���Ѿ������ˣ�"+RANK_D->query_respect(ob)+
			"�����������ɡ�\n"NOR
			: ( (time <= 60) ? CYN"��ʯ�̶�����ͷ�����Ͼ�Ҫ�����ˣ���λ�͹����һ�°ɡ�\n"NOR
			: CYN"��ʯ�̴��˸�����˵����С�껹û�п��ţ��������������ɡ�\n"NOR ) );
		return;
	}
	else
	{
		switch( random(2) )
		{
                case 0:
                        say( CYN"��ʯ��Ц�����˵�����������и�ʽ�Ŀ�ʯ���͹�Ҫ��Ҫ��������\n"NOR);
                        break;
                case 1:
                        say( CYN"��ʯ��˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n"NOR);
                        break;
		}
	}
	
}*/