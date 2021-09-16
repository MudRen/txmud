// seller.c

inherit F_DEALER;

void create()
{
	set_name("С�̷�", ({ "seller" }) );
	set("gender", "����" );
        set("age", 37);
        set("long","����һλ���ڴ󺰴�������������С����\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
	set("sell_all_day",1);

	set("vendor_goods", ([
		FOOD_DIR"dumpling":-1,
		__DIR__"obj/waterskin":-1,
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

	say(sprintf("%sߺ�ȵ�����ǰ��·�ܳ���λ%s����Ժȴ��ϰɡ���\n",name(),RANK_D->query_respect(ob)));
}