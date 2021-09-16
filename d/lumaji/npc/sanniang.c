// sanniang.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("������", ({ "san niang" }) );
	set("title","�ӻ�������");
        set("gender", "Ů��" );
        set("age", 35);
        set("long","��������΢Ц�ſ����㡣\n");
        set("combat_exp", 50);

        set("attitude", "friendly");
	set("sell_all_day",1);

	set("chat_chance", 5);
	set("chat_msg",({
		CYN"������˵����������կ�Ĵ����˵��ǲ����������۸�����С�ϰ��ա���\n"NOR,
		CYN"������˵������ÿ�괺���������֣����ص����Ӷ�Ҫ������\n"NOR,
		CYN"������˵�������������ﾩ�ǲ�Զ����һ��Ұζȥ��Ҳ�������١���\n"NOR,
}));

        set("vendor_goods", ([
		MISC_DIR"torch":20,
		FOOD_DIR"dumpling":-1,
		LIQUID_DIR"wineskin":20,
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
		return;
	}

	if(!is_day())
	{
		sscanf( day_night(),"%s %d",day_night,time);
		say( (time > 480) ? CYN"��ô����죬��һ���Ǹոϵ��������������ӵ�漢�ɡ�\n"NOR
			: ( (time <= 60) ? CYN"�������������Ҫ��·�ɣ��򼸸����Ӵ���·�ϡ�\n"NOR
			: CYN"�������˸�����˵�����͹���Ҫʲô�����ⶼ���ֳɵġ�\n"NOR ) );
		return;
	}
	else
		say( CYN"������Ц�����˵�����͹����������С������ľơ�\n"NOR);
}