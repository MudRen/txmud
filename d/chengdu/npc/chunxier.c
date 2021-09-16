// chunxier.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("春喜儿", ({ "chun xi er" }) );
        set("title","茶馆小二");
        set("gender", "男性" );
        set("age", 22);
        set("sell_all_day",1);
        set("long","这是一位个子很矮的小伙子。\n");
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
			message_vision( sprintf(CYN"$N朝着$n唱道：%s%s，请喝一杯茶呀，请喝一杯茶。。。\n"NOR,
				ob->query("name")[0..1],
				ob->query("gender")=="男性"?"大哥":"大姐"),
				this_object(),ob);
			break;
		case 1:
			message_vision( CYN"$N朝着$n唱道：这里的茶水甜又香呀，甜又香呀。。。\n"NOR,
				this_object(),ob);
			break;
	}
}
