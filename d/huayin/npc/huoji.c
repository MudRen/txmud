// paotang.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("С���", ({ "huo ji" }) );
        set("gender", "����" );
        set("age", 22);
        set("long","С�������æ�ţ�����ʱҪ�ͽ���
�Ŀ��˴��к���\n");

	set("sell_all_day",1);
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		FOOD_DIR"chicken_leg" : 30,
		LIQUID_DIR"bowl" : 30,
        ]) );
        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

	::init();
        if( living(ob = previous_object()) && random(2) && !is_fighting() && !wizardp(ob))
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	say( CYN"С����һ����˵������λ" + RANK_D->query_respect(ob)
		+ "����������\n"NOR);
}