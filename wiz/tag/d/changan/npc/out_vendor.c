#include <ansi.h>
inherit F_DEALER;

void create()
{
        set_name("�������", ({ "trader" }) );
        set("gender", "����" );
        set("age", 46);
        set("long", "����һλ����ģ�����ˣ���װ���Ͽ��Ǵ�������ġ�\n");
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
        CYN"������������������������ͷ���ҵ�û������ѣ������Ѱ�����\n"NOR,
        CYN"�������̾��������֪Ϲ�����Щ�������ô������\n"NOR,
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

        say( CYN"�������˵��������λ" +RANK_D->query_respect(ob)+ "���뿴�������ĺö���ô��\n"NOR, ob);
}