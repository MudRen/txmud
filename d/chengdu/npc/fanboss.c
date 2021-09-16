// fanboss.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("����", ({ "fan song","boss" }) );
        set("title","���跻�ϰ�");
        set("gender", "����" );
        set("age", 52);
        set("sell_all_day",1);
        set("long","����һλ�����������Ƶ��������ӡ�\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/huangya":10,
                __DIR__"obj/shihua":10,
                __DIR__"obj/maofeng":10,
                __DIR__"obj/queshi":10,
                __DIR__"obj/gongfu":5,
                __DIR__"obj/huacha":20,

        ]) );
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

        ::init();
	if( living(ob = previous_object()) && !is_fighting() && userp(ob))
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob
        || (environment(ob) != environment())
        || file_name(environment()) != this_object()->query("startroom"))
                return;
 
	if(!random(3))
		say( CYN"����˵������λ" + RANK_D->query_respect(ob)
			+ "�������Ҷ�İɡ�\n"NOR);
}
