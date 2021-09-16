#include <ansi.h>
inherit F_DEALER;

void create()
{
        set_name("外地商人", ({ "trader" }) );
        set("gender", "男性" );
        set("age", 46);
        set("long", "这是一位商人模样的人，从装束上看是从外地来的。\n");
        set("attitude", "peaceful");
        set("combat_exp", 12000);

        set("sell_all_day", 1);
        set("vendor_goods",([
        __DIR__"obj/literate_book1"   :   1,
        __DIR__"obj/literate_book2"   :   1,
        __DIR__"obj/literate_book3"   :   1,
        __DIR__"obj/magic_book"       :   1,
        ]));
        
        set("chat_chance", 2);
        set("chat_msg", ({
        (: random_move :),
        CYN"外地商人自言自语道：“这年头想找点好货真是难！真是难啊！”\n"NOR,
        CYN"外地商人叹道：“不知瞎子李近些年过得怎么样。”\n"NOR,
        }));

        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);

        setup();
        add_money("silver", 20);
        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( living(ob = previous_object()) && !is_fighting() && !wizardp(ob))
        {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
}

void greeting(object ob)
{

        if( !ob
        || (environment(ob) != environment()))        
                return;

        say( CYN"外地商人说道：“这位" +RANK_D->query_respect(ob)+ "不想看看我卖的好东西么？\n"NOR, ob);
}
