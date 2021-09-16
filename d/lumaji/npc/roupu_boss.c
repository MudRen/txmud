// roupu_boss.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
	set_name("�����ϰ�", ({ "roupu boss", "boss" }) );
	set("gender", "����" );
        set("age", 45);
        set("long","����һλ����΢Ц�Ĵִ��ӡ�\n");
        set("combat_exp", 10000);

        set("attitude", "friendly");
	set("sell_all_day",1);

	set("chat_chance", 5);
	set("chat_msg",({
		CYN"�����ϰ�˵�����������������������Ĵ��Ը���,ÿ�γ��Զ��ܴ�����Ұζ��������\n"NOR,
		CYN"�����ϰ�˵��������˵���ϵ�����С·�����ϻ����˽ٵ�������,����������\n"NOR,
}));

        set("vendor_goods", ([
		__DIR__"obj/turou":5,
		__DIR__"obj/lurou":5,
		__DIR__"obj/zhurou":5,
        ]) );

	set_skill("dodge",90);
	set_skill("parry",90);
	set_skill("blade",90);

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
	carry_object(__DIR__"obj/tigu_blade")->wield();
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

	say( CYN"�����ϰ�΢Ц��˵������λ" + RANK_D->query_respect(ob)
		+ "���������������Ұζ�ɡ�\n"NOR);

}
