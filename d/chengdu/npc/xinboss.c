// xinboss.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
	set_name("��ƽ", ({ "xin ping" }) );

	set("title","ˮ�����ϰ�");
	set("gender", "����" );
	set("age", 32);
	set("per",18);

	set("sell_all_day",1);

	set("long","����һλ��ò�Һ�������ˣ���˵���ھ��ǵ���
��ؤ����Ȼ���������һ��С�ϰ壬�����˾���
����˼��\n");

	set("combat_exp", 50);
	set("attitude", "friendly");
	set("vendor_goods", ([
		__DIR__"obj/xuecheng":10,
		__DIR__"obj/liangpingyou":10,

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
        || file_name(environment()) != query("startroom"))
		return;
 
        switch( random(3) )
        {
		case 0:
			say( CYN"��ƽ˵������λ" + RANK_D->query_respect(ob)
				+ "�������\n"NOR);
			break;
		case 1:
			say( CYN"��ƽ˵������λ" + RANK_D->query_respect(ob)
				+ "��Ҫ�Ե�ʲôˮ����\n"NOR);
			break;
	}
}
