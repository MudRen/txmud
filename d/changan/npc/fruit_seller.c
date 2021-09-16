// design by ���ֺ�(find) . all right reserved.

// fruit_seller.c
#include <ansi.h>

inherit F_DEALER;

void steal_it();

void create()
{
	/* ������ˮ������ */
	set_name("ˮ������", ({ "fruit seller","seller" }) );
	set("title","�����̻�");
	set("nickname",HIY"ͯ������"NOR);
	set("long", "һ����ˮ����С���������𾢵������˶���ˮ����\n");

	/* ������С͵ */
	set_night_name("����",({ "thief",}));
	set("night_title","�������̻�");
	set("night_nickname",HIB"���ִ�ʥ"NOR);
	set("night_long","һ����ü���۵ļһ�,��֪�ڶ����㿴ʲô��\n");

	/*
	 * �������ϲ����̷�,����������,
	 * ���������ε� list mai ��Щ����
	 * ���Ҫ�ڰ������ε� list mai ����
	 * �� set("no_sell_day",1);
	 */

	set("no_sell_night",1);

	set("chat_chance", 5); /*��������ĸ���*/

	/* ��������������ߺ�� */
	set("chat_msg",({
		CYN"ˮ������˵���������ˮ���ɣ��������ʡ���\n"NOR,
		CYN"ˮ������˵��������ƽ���ף�ͯ�����ۡ���\n"NOR,
		}));

	/* ���ϵ����������͵ͬ����������ϵĶ��� */
	set("night_chat_msg",({
		"���������һ�ۣ���֪��ʲô���⡣\n",
		(: steal_it :),
		}));

	set("gender", "����" );
	set("age", 28);

	set("combat_exp", 5000);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
	set_skill("dodge", 100);
	set_skill("throwing", 30);

	set("vendor_goods", ([
		__DIR__"obj/apple":5,
		__DIR__"obj/pear":5,
		__DIR__"obj/strawberry":5,
		__DIR__"obj/grape":5,
		__DIR__"obj/melon":5,
	]) );

	setup();
	add_money("silver", 1);
	add_money("coin", 100);
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	/* ������С͵����ߺ�ȡ�*/
	if( !is_day()) return;
        switch( random(2) ) {
                case 0:
                        say( "ˮ�����Ӹߺ�����ˮ���������������ˮ����\n");
                        break;
                case 1:
                        say( "ˮ�����Ӹߺ����ֽ���ֳ伢����\n");
                        break;
        }
}

void steal_it()
{
	object *inv;
	int i;

	inv = all_inventory(environment());
	for(i=0;i<sizeof(inv);i++)
	{
		if(!userp(inv[i]))
			continue;
		if(is_busy())
			continue;
		command("steal all from "+inv[i]->query("id"));
		break;
	}
}