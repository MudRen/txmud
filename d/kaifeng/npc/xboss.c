#include <ansi.h>
inherit F_DEALER;

void create()
{
        set_name("������", ({ "xiaoxiang yue", "yue" ,"xiaoxiang"}) );
        set("gender", "����" );
        set("title",HIW"����������--��ѩ����"NOR);
        set("age", 24);

        set("long", "�������Ǹ�Ӣ�������Ĺ��Ӹ硣\n");

        set("combat_exp", 50000);

        set_skill("parry",180);
        set_skill("dodge",180);
        set_skill("unarmed",180);
        set_skill("force",180);

        set("attitude", "friendly");

        set("sell_all_day",1);

        set("vendor_goods", ([
                __DIR__"obj/xiao" : -1,
        ]) );


        setup();
        add_money("silver", 1);
        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() )
                return;

        switch( random(4) )
        {
                case 0:
                        command(sprintf("say ��λ%s����ʲô������", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say ����ȫ��Ӫҵ��������ʱ���١�");
                        break;
        }
}

