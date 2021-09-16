// chunxier.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("��ϲ��", ({ "chun xi er" }) );
        set("title","���С��");
        set("gender", "����" );
        set("age", 22);
        set("sell_all_day",1);
        set("long","����һλ���Ӻܰ���С���ӡ�\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/chahu":10,

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
			message_vision( sprintf(CYN"$N����$n������%s%s�����һ����ѽ�����һ���衣����\n"NOR,
				ob->query("name")[0..1],
				ob->query("gender")=="����"?"���":"���"),
				this_object(),ob);
			break;
		case 1:
			message_vision( CYN"$N����$n����������Ĳ�ˮ������ѽ��������ѽ������\n"NOR,
				this_object(),ob);
			break;
	}
}
