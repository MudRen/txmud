// longboss.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("������", ({ "long shao yin" }) );
        set("title","�ش����ϰ�");
        set("gender", "����" );
        set("age", 34);
        set("sell_all_day",1);
        set("long","����һλ��������������ˡ�\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
                DRUG_DIR"medicine_ganmao":-1,
                DRUG_DIR"huandan":50,
                DRUG_DIR"s_hd":30,
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
 
        switch( random(4) )
        {
                case 0:
                        say( CYN"����˵������λ" + RANK_D->query_respect(ob)
                                + "������ʲô����\n"NOR);
                        break;
                case 1:
                        say( CYN"����˵������λ" + RANK_D->query_respect(ob)
                                + "��Ҫ��ҩ��\n"NOR);
                        break;
        }
}

