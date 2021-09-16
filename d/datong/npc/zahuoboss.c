// zahuoboss.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
	set_name("����", ({ "hu mai","boss" }) );
	set("title","�ӻ����ϰ�");
        set("gender", "����" );
        set("age", 42);
	set("sell_all_day",1);
        set("long","����һλ��С�ݸɵ������ˡ�\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		MISC_DIR"bag":20,
		MISC_DIR"torch":20,
		__DIR__"obj/rope" : 4,
		BOOK_DIR"force_book" : 2,
		MISC_DIR"top" : 50,
		"/obj/mine/sz_gao" : 50,
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
	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	switch( random(2) )
	{
		case 0:
			say( CYN"�����˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n"NOR);
			break;
		case 1:
			say( CYN"�����˵������λ" + RANK_D->query_respect(ob)
				+ "Ҫ���ʲô��\n"NOR);
			break;
	}
}