// hundun_seller.c

inherit F_DEALER;

void create()
{
	set_name("�����С��", ({ "huntun seller","seller" }) );
	set("gender", "����" );
        set("age", 37);
        set("long","����һλ����⽵�С����һ�������һ��
�𾢵�ߺ���š�\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
	set("sell_all_day",1);

	set("vendor_goods", ([
		__DIR__"obj/huntun":20,
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
	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	say(sprintf("%sߺ�ȵ�������λ%sЪЪ��������⽰ɡ���\n",name(),RANK_D->query_respect(ob)));
}